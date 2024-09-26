#include <iostream>
#include <string>
using namespace std;

void reverse(string str) {
    if (str.length() != 1) reverse(str.substr(1, str.length() - 1));
    cout << str[0];
}

int main() {
    string input;

    cin >> input;

    reverse(input);

    return 0;
}