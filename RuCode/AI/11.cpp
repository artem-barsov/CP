#include <bits/stdc++.h>

using namespace std;

int main() {
    int l = 0, r = 100001, x = (l+r)/2;
    cout << "? " << x << '\n';
    fflush(stdout);
    // cout.flush();
    char response = '.';
    while (response != '=') {
        cin >> response;
        if (response == '>') {
            r = x;
            x = (l+r)/2;
        }
        else {
            l = x;
            x = (l+r)/2;
        }
        cout << x << '\n';
        fflush(stdout);
        // cout.flush();
    }
}
