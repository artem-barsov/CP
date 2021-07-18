#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (auto& el : a) std::cin >> el;
    for (auto& el : b) std::cin >> el;
    for (auto& el : c) std::cin >> el;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int ans = 0;
    int i = 0, j = 0, k = 0;
    while (true) {
        j = distance(b.begin(), upper_bound(next(b.begin(), j), b.end(), a[i]));
        if (j == n) break;
        k = distance(c.begin(), upper_bound(next(c.begin(), k), c.end(), b[j]));
        if (k == n) break;
        i++, j++, k++, ans++;
    }
    std::cout << ans << '\n';
}
