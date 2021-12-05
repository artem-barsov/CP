#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int asum(int a, int n) {
    return n * (2 * a + n - 1) / 2;
}

void prnt(int sum, int a, int n) {
    cout << sum << " = " << a;
    for (int i = 1; i < n; i++) {
        cout << " + " << a + i;
    }
    cout << endl;
}

void solve() {
    int sum;
    cin >> sum;
    if (sum == 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if (sum % 2) {
        prnt(sum, sum / 2, 2);
        return;
    }
    for (int i = 2; i * i <= 2 * sum; i++) {
    	if (2 * sum % i != 0)
        	continue;
        int a = ((2 * sum) / i + 1 - i);
        a /= 2;
        if (a <= 0)
            continue;
        if (asum(a, i) == sum) {
            prnt(sum, a, i);
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    signed t;
    cin >> t;
    while(t--)
        solve();
}
