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
    int n;
    cin >> n;
    map<pair<int, int>, int> coord_val;
    map<int, int> hor_sums, ver_sums;
    map<int, vector<int> > coord_list;
    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        coord_val[{x, y}] = v;
        hor_sums[y] += v;
        ver_sums[x] += v;
        coord_list[x].push_back(y);
        coord_list[y].push_back(x);
    }
    
    int x_max_sum = 0;
    int x_del;
    for (auto& [x, sum] : ver_sums) {
        if (x_max_sum < sum) {
            x_max_sum = sum;
            x_del = x;
        }
    }
    // cout << x_del << " : " << x_max_sum << '\n';
    int y_max_sum = 0;
    int y_del;
    for (auto& [y, sum] : hor_sums) {
        if (y_max_sum < sum) {
            y_max_sum = sum;
            y_del = y;
        }
    }
    // cout << y_del << " : " << y_max_sum << '\n';
    if (x_max_sum > y_max_sum)
}