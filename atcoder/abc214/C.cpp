#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> s(n), t(n);
    int mint = 1e9 + 1, idx;
    for (auto& x : s) std::cin >> x;
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
        if (mint > t[i]) {
            mint = t[i];
            idx = i;
        }
    }
    std::vector<int> fir(n, -1);
    fir[idx] = mint;
    for (int i = idx+1; i < n + idx+1; i++) {
        int j = i % n;
        int prev = (!j ? n-1 : j-1);
        fir[j] = min(fir[prev] + s[prev], t[j]);
    }
    for (auto& x : fir) std::cout << x << '\n';
}
