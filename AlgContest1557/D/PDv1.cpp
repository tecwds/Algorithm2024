//
// Created by wpan on 10/30/24.
//
#include<bits/stdc++.h>
using namespace std;

bool mp[5][5] = {{0, 0, 1, 1, 0},
                 {1, 1, 0, 0, 1},
                 {0, 1, 1, 0, 0},
                 {0, 0, 0, 1, 0},
                 {0, 1, 0, 0, 1}};
bool vis[6];

int ans[6], cnt;

string s[] = {"Zhang", "Wang", "Liu", "Sun", "Li"};

char c[] = {'A', 'B', 'C', 'D', 'E'};

//answer 1:
//Student Zhang:C
//Student Wang:A
//Student Liu:B
//Student Sun:D
//Student Li:E
void print(){
    cout << "answer " << ++cnt << ":\n";
    for(int i = 0;i < 5;i ++){
        cout << "Student " << s[i] << ':' << c[ans[i]] << '\n';
    }
}

//void dfs(int d){
//	for(int i = 0;i < 5;i ++){
//		if(mp[d][i] && !vis[i]){
//			vis[i] = true;
//			ans[d] = i;
//			if(d == 4){
//				print();
//			}else dfs(d + 1);
//			vis[i] = false;
//		}
//	}
//}

void dfs(int d){
    if(d == 5){
        print();
    }else {
        for(int i = 0;i < 5;i ++){
            if(mp[d][i] && !vis[i]){
                vis[i] = 1;
                ans[d] = i;
                dfs(d + 1);
                vis[i] = false;
            }
        }
    }
}

int main(){
    memset(vis, 0, sizeof vis);
    dfs(0);
    return 0;
}