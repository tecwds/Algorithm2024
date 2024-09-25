#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    // getchar();

    for (int i = 0; i < t; i++) {
        int ascii;
        cin >> ascii;
        cout << static_cast<char>(ascii);  
    }

    return 0;
}