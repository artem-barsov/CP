#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n), w;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int ones = 0;
    for (int i = 0; i < k; i++) {
        int inp;
        std::cin >> inp;
        if (inp == 1) ones++;
        else w.push_back(inp);
    }
    sort(a.begin(), a.end(), [](const int& lhs, const int& rhs){return lhs>rhs;});
    sort(w.begin(), w.end(), [](const int& lhs, const int& rhs){return lhs>rhs;});
    long long sum = 0;
    for (int i = 0; i < ones; i++) sum += 2*a[i];
    for (int i = 0; i < w.size(); i++) sum += a[ones+i];
    for (int i = 0, idx = n-1; i < w.size(); i++) {
        sum += a[idx];
        idx -= w[i]-1;
    }
    std::cout << sum << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
