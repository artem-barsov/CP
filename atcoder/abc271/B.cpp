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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for (auto &&ai : a)
    {
        int l;
        cin >> l;
        for (int i = 0; i < l; i++) {
            int aij;
            cin >> aij;
            ai.push_back(aij);
        }
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        cout << a[s-1][t-1] << '\n';
    }
}