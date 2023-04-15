#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    std::vector<int> skip(*max_element(a.begin(), a.end()) + 1);
    for (int i = n-1, j = n-1; i >= 0 && j >= 0;) {
        if (a[i] != b[j]) {
            if (skip[a[i]]) {
                skip[a[i]]--;
                i--;
                continue;
            }
            // printf("a[%d]=%d, a[%d]=%d\n", i, a[i], j, b[j]);
            std::cout << "NO" << '\n';
            return;
        }
        j--;
        if (b[j] != b[j+1]) i--;
        else                skip[b[j]]++;
    }
    std::cout << "YES" << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
