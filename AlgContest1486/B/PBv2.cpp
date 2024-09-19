#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

map<char, int> table;

string str;

int main() {
    table['A'] = 4;
    table['B'] = 3;
    table['C'] = 2;
    table['D'] = 1;
    table['F'] = 0;

    while (getline(cin, str)) {
        double sum = 0;
        int num = 0;
        bool flag = false;
        for (int i = 0; i < str.size(); i++) {
            if (
                str[i] == 'A' ||
                str[i] == 'B' ||
                str[i] == 'C' || 
                str[i] == 'D' || 
                str[i] == 'F'
            ) {
                sum += table[str[i]];
                num++;
            } else if (str[i] != ' ') {
                cout << "Unknown" << endl;
                flag = true;
                break;
            } 
        }
        if (!flag) {
            cout << fixed << setprecision(2) << sum/(double)num << endl;
        }
    }
    return 0;
}