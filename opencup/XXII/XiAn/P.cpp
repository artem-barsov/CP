#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n){
        vector<int> a(n+1);
        for (auto &it : a) cin >> it;
        vector<int> b(n+1, -1);
        int m = 0;
        for (;1 << m <= n; m++) {}
        for (int i = m; i >= 0; i--) {
            int t = 1 << i;
            for (int d = t, u = t - 1; d <= n && u >= 0; d++, u--) {
                if (b[d] == -1 && b[u] == -1) {
                    b[d] = u;
                    b[u] = d;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (b[i] == -1)
            b[i] = i;
        }
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += a[i] ^ b[a[i]];
        }
        cout << ans << endl << b[a[0]];
        for (int i = 1; i <= n; i++) {
            cout << ' ' << b[a[i]];
        }
        cout << endl;
    }
}
