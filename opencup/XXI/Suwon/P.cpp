#include <bits/stdc++.h>

using namespace std;

int prod(std::vector<int>& v) {
    int ret = 1;
    int i = v.size()-1;
    while (!v[i]) i--;
    for (; i >= 0; i--) {
        if (!v[i]) return 0;
        ret *= v[i];
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    if (n < 10) {
        std::cout << n << '\n';
        return 0;
    }
    int l = ceil(log10(n));
    std::vector<int> v;
    while (n) {
        v.push_back(n%10);
        n /= 10;
    }
    int ans = prod(v);
    int r = 0;
    for (int i = 0; i < l; i++) {
        v[r] = 9;
        v[++r]--;
        if (v[r] < 0) continue;
        ans = max(ans, prod(v));
    }
    std::cout << ans << '\n';
}
