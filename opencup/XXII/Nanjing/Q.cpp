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
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<long long> ps(n + 1);
    for (int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[i];
    std::map<long long, std::set<int> > bounds;
    for (int i = 0; i < n + 1; i++) {
        if (bounds[ps[i]].size() < 2)
            bounds[ps[i]].insert(i);
        else if (i < *bounds[ps[i]].begin()) {
            bounds[ps[i]].erase(bounds[ps[i]].begin());
            bounds[ps[i]].insert(i);
        }
        else if (*std::prev(bounds[ps[i]].end()) < i) {
            bounds[ps[i]].erase(std::prev(bounds[ps[i]].end()));
            bounds[ps[i]].insert(i);
        }
    }
    int max_l = 0;
    for (auto& [_,lr] : bounds) {
        if (lr.size() == 2) {
            max_l = max(max_l, *std::prev(lr.end()) - *lr.begin());
        }
    }
    std::cout << max_l << '\n';
}
