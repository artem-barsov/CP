#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    vector<string> sa(n);
    for (int i = 0; i < n; i++) {
        sa[i] = to_string(a[i]);
    }
    sort(sa.begin(), sa.end());
    for (auto &&s : sa)
        cout << s << ' ';
    cout << '\n';
}