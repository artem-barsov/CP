#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void solve() {
    long long n, u, v;
    cin >> n >> u >> v;
    if (u == v) {cout << 0 << endl; return;}
    if (u > v) {long long t = u; u = v; v = t;}
    if (v == n) {cout << -1 << endl; return;}
    long long ans = 0;
    for (;v > 0 && u > 0; ans++) {
        if (u == v) {cout << ans << '\n'; return;}
        if (v > u && n % v != 0) {
            v = v - (n % v);
        }
        else if (n % u != 0){
            u = u - (n % u);
        }
        else break;
    }
    cout << -1 << '\n';
    return;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) solve();
}
