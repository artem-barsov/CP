#include <bits/stdc++.h>

using namespace std;

int main() {
    int l = 0, r = 17, x = (l+r)/2;
    cout << x << '\n';
    cout.flush();
    // fflush(stdout);
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
        cout.flush();
        // fflush(stdout);
    }
}
