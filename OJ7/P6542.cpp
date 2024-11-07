#include<iostream>
using namespace std;
string s, a;

int main() {
   for (; cin >> a; s += a[0]);
   cout << (s == "prr" || s == "rss" || s == "spp"
               ? 'F'
               : s == "rpr" || s == "srs" || s == "psp"
                    ? 'M'
                    : s == "rrp" || s == "ssr" || s == "pps"
                         ? 'S'
                         : '?');
}
