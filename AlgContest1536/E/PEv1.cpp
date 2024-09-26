#include <iostream>
using namespace std;

size_t ans;

void what_can_i_say(size_t len, size_t wid) {
    if (len == wid) {
        ans++;
        return;
    }
    if (len > wid) swap(len, wid);
    ans++;
    what_can_i_say(wid - len, len);
}

int main() {
    size_t len;
    size_t wid;

    cin >> len >> wid;

    what_can_i_say(len, wid);

    cout << ans << endl;

    return 0;
}