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
    vector<vector<int>> d(r, vector<int>(c));
    cin >> d;
    int maxl = 0, mr = 0, mc = 0;
    for (int i = 1; i < r-1; i++) {
        for (int j = 1; j < c-1; j++) {
            for (int l = 1; i-l>=0&&j-l>=0&&i+l<r&&j+l<c; l++) {
                if (d[i-l][j]==d[i+l][j]&&d[i][j-l]==d[i][j+l]&&d[i-l][j]==d[i][j-l]) {
                    if (maxl < l) {
                        maxl = l;
                        mr = i;
                        mc = j;
                    }
                }
                else break;
            }
        }
    }
    cout << maxl << ' ' << mr+1 << ' ' << mc+1 << '\n';
}