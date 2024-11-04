//
// Created by wpan on 10/29/24.
//
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

stack<char> q;

void print(){
    while(!q.empty()){
        cout << q.top();
        q.pop();
    }
}

int main(){
    int n;
    cin >> n;
    cin.ignore();

    while(n > 0){
        string s;
        getline(cin, s);
        for(char c : s){
            if(c == ' '){
                print();
                cout << ' ';
            }else {
                q.push(c);
            }
        }
        print();
        cout << '\n';
        n--;
    }
    return 0;
}