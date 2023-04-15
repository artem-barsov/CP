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
    for (auto&& x : a) cin >> x;
    vector<int> c;
    for (int i = n/2+1; i <= n; i++)
        c.push_back(i);
    for (int i = 1; i <= n/2; i++)
        c.push_back(i);
    cout << n / 2 << '\n';
    for (int x : a)
        cout << c[x-1] << ' ';
    cout << '\n';
}