#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, s = 0;
    cin >> n >> s;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    vector<int> d(n), p(n);
    for (int i = 0; i < n; ++i) {
        d[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; ++j) {
            if ((v[j].second < v[i].second) && ((v[i].first - v[j].first) <= s)
            && ((v[i].first - v[j].first) >= 0) && (1 + d[j] > d[i])) {
                d[i] = 1 + d[j];
                p[i] = j;
            }
        }
    }
    int ans = d[0], pos = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }
    cout << ans << endl;
    vector<int> path;
    while (pos != -1) {
        path.push_back(pos);
        pos = p[pos];
    }
    reverse(path.begin(), path.end());
    vector<bool> ok(n, false);
    for (int i = 0; i < (int)path.size(); ++i)
        ok[v[path[i]].second] = true;

    for (auto i : ok) std::cout << i << ' ';
    cout << endl;
}
