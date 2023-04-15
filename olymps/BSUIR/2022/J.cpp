#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Graph = vector<vector<int>>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string p = "BSUIROPEN";

    int n;
    std::string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < 9 * n; ++i) {
        if (s[i] != p[i % 9]) ++ans;
    }

    cout << ans << endl;

    return 0;
}
