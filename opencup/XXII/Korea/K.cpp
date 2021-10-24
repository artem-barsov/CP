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
    std::string s;
    std::cin >> n >> s;
    std::set<int> beads;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') beads.insert(i + 1);
    }
    int q;
    std::cin >> q;
    while (q--) {
        int k;
        std::cin >> k;
        auto it = beads.lower_bound(k);
        if (*it == k) beads.erase(it);
        else          beads.insert(it, k);
        int l = *beads.begin();
        int r = *std::prev(beads.end());
        std::cout << min(n - l, r - 1) - beads.size() + 1 << '\n';
    }
}
