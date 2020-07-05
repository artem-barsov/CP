#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    std::vector<int> gefahr(n);
    for (size_t i = 0; i < n; i++) std::cin >> gefahr[i];
    sort(gefahr.begin(), gefahr.end());
    int q;
    std::cin >> q;
    for (size_t i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << (lower_bound(gefahr.begin(), gefahr.end(), max(l,r))-gefahr.begin()) - (upper_bound(gefahr.begin(), gefahr.end(), min(l, r))-gefahr.begin()) << '\n';
    }
}
