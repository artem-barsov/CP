#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> meet(n, vector<char>(n, false));
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (auto&& x : a) cin >> x;
        for (auto&& m1 : a) for (auto&& m2 : a) {
            meet[m1-1][m2-1] = true;
            meet[m2-1][m1-1] = true;
        }
    }
    for (auto &&man : meet) {
        if (!all_of(man.begin(), man.end(), [](const bool x){return x;})) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
}