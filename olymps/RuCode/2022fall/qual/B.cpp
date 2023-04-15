#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto &&x : v) is >> x;
    return is;
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    cin >> a;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r-1; j++) {
            cout << a[j][i] << ' ';
        }
        cout << a[r-1][i] << '\n';
    }
}