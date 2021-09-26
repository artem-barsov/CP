#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        ll x = 0;
        while (n--) {
            ll a;
            cin >> a;
            x ^= a;
        }
        if (x) {
            cout << "Win\n";
            continue;
        }
        cout << "Lose\n";
    }
}
