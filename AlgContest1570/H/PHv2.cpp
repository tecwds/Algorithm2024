#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

const int N = 1e5 + 5;
string st;
pair<bool, int> pf[N]; //<类型(0-num,1-op),数字/运算符>
int pftop = 0;
stack<char> op; //<运算符>

inline int type(char ch) {
	if (ch >= '0' && ch <= '9') return 0;
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return 1;
	if (ch == '(' || ch == ')') return 2;
	return -1;
}

inline int priority(char op) {
	if (op == '+' || op == '-') return 0;
	if (op == '*' || op == '/') return 1;
	return -1;
}

bool Check_and_Preprocessing() //1、检查是否合法，并预处理
{
	bool FlagOfAt = false;
	for (int i = 0; i < st.length(); i++) //（1）检查是否有'@'并删除其及以后所有内容
		if (st[i] == '@') {
			st.erase(i);
			FlagOfAt = true;
			break;
		}
	if (!FlagOfAt) return false;

	int LeftBracketsCount = 0;
	for (int i = 0; i < st.length(); i++) //（2）检查括号是否匹配
	{
		if (st[i] == '(') LeftBracketsCount++;
		if (st[i] == ')') LeftBracketsCount--;
		if (LeftBracketsCount < 0) return false;
	}
	if (LeftBracketsCount) return false;

	string tmpst;
	for (int i = 0; i < st.length(); i++) //（3）预处理负号
	{
		if (st[i] == '-') {
			if (!i) tmpst += '0'; //a. -...
			else if (st[i - 1] == '(') tmpst += '0'; //b. ...(-x)...
		}
		tmpst += st[i];
	}
	st = tmpst;

	if (type(st[0]) == 1 || st[st.length() - 1] == 1 || type(st[0]) == -1) return false; //（4）检查运算符是否合法
	for (int i = 1; i < st.length(); i++) {
		if (type(st[i]) == -1) return false; //a.出现非法符号
		if (type(st[i]) == 1) //b.运算符两侧不为数或括号
		{
			if (type(st[i - 1]) == 1 || type(st[i + 1]) == 1) return false; //b i.+*
			if (st[i - 1] == '(' || st[i + 1] == ')') return false; //b ii.(+)
		}
	}

	return true; //（5）你过关！
}

void PostfixExpression() //2、先将中缀表达式转换为后缀表达式
{
	for (int i = 0; i < st.length(); i++) //（1）依次扫描中缀表达式
	{
		if (!type(st[i])) //（2）遇到数字输出到后缀表达式
		{
			int x = 0;
			while (st[i] >= '0' && st[i] <= '9') {
				x = (x << 3) + (x << 1) + (st[i] ^ 48);
				i++;
			}
			pf[++pftop] = make_pair(0, x);
			i--;
		} else //（3）遇到运算符，有以下几种情况
		{
			if (op.empty() || st[i] == '(') op.push(st[i]); //a:栈空直接入栈;b:遇到’(‘直接入栈
			else if (st[i] == ')') //c:遇到’)‘一直出栈并输出，直到’(‘出栈为止，但’('不作为输出（因为后缀表达式中没有括号）
			{
				while (op.top() != '(') {
					pf[++pftop] = make_pair(1, op.top());
					op.pop();
				}
				op.pop();
			} else {
				if (priority(st[i]) > priority(op.top())) //d:遇到运算符优先级高于栈顶运算符优先级，则入栈
					op.push(st[i]);
				else //e:遇到运算符优先级低于或等于栈顶运算符优先级，则出栈，直到其优先级高于栈顶运算符优先级时停止或栈为空）,最后再将其入栈
				{
					while (!op.empty() && priority(st[i]) <= priority(op.top())) {
						pf[++pftop] = make_pair(1, op.top());
						op.pop();
					}
					op.push(st[i]);
				}
			}
		}
	}
	while (!op.empty()) {
		pf[++pftop] = make_pair(1, op.top());
		op.pop();
	}
	return;
}

stack<int> calc;

inline int calc_op(char op, int x, int y) {
	if (op == '+') return x + y;
	if (op == '-') return x - y;
	if (op == '*') return x * y;
	if (op == '/') return x / y;
	return 0;
}

inline int Calculate() //3、计算后缀表达式的值
{
	for (int i = 1; i <= pftop; i++) {
		if (pf[i].first) //（1）读取到符号
		{
			int t1 = calc.top();
			calc.pop();
			int t2 = calc.top();
			calc.pop();
			calc.push(calc_op(pf[i].second, t2, t1));
		} else calc.push(pf[i].second); //（2）读取到数字
	}
	return calc.top();
}

int main() {
	getline(cin, st);
	if (!Check_and_Preprocessing()) {
		printf("NO\n");
		return 0;
	}
	PostfixExpression();
	int ans = Calculate();
	printf("%d\n", ans);
	return 0;
}
