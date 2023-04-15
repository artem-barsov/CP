#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ask(ll l, ll r) {
    cout << "? " << l << ' ' << r << '\n';
    fflush(stdout);
    ll resp;
    cin >> resp;
    return resp;
}

int main(int argc, char const *argv[]) {
    for (int i = 1; i <= 25; i++) {
        ll resp1 = ask(i, i+1);
        if (resp1 == -1) {
            cout << "! " << i+1 << '\n';
            fflush(stdout);
            return 0;
        }
        ll resp2 = ask(i+1, i);
        if (resp1 != resp2) {
            cout << "! " << resp1 + resp2 << '\n';
            fflush(stdout);
            return 0;
        }
    }
}