#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &&x : v) os << x << ' ';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<vector<T>>& v) {
    for (auto &&x : v) os << x << '\n';
    return os;
}

void dfs(set<vector<int>>& vvout, vector<int>& c, int n, int m) {
    if (n == 0) {
        vector<int> sorted = c;
        sort(sorted.begin(), sorted.end(), greater<int>());
        vvout.insert(sorted);
        return;
    }
    for (int i = min(n, m); i >= 1; i--) {
        c.push_back(i);
        dfs(vvout, c, n - i, i);
        c.pop_back();
    }
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    set<vector<int>> vvout;
    dfs(vvout, *(new vector<int>), n, n);
    cout << vvout;
}