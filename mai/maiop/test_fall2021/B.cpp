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
    unsigned long long om;
    std::cin >> n >> om;
    std::vector<std::pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (auto& [val, _] : a) {
        if (om > val) om += val;
        else {
            std::cout << "NO" << '\n';
            return 0;
        }
    }
    std::cout << "YES" << '\n';
    for (auto& [_, id] : a)
        std::cout << id + 1 << ' ';
    std::cout << '\n';
}
