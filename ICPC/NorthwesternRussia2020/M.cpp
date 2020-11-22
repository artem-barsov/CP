#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> x(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    sort(x.begin(), x.end());
    int y = 0;
    int maxl = 0, minr = 1e9 + 1;
    for (size_t i = 0; i < n-1; i++) {
        maxl = max(maxl, x[i]-y);
        minr = min(minr, x[i+1]-y);
        y = x[i];
    }
    maxl = max(maxl, x.back()-y);
    if (maxl < minr)
        std::cout << maxl << '\n';
    else
        std::cout << 0 << '\n';
}
