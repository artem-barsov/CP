#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

void solve() {
    int n;
    ull k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int maxa = INT_MIN, mina = INT_MAX;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
    }
    if (k&1)
        for (int i = 0; i < n; i++)
            std::cout << maxa - a[i] << ' ';
    else
        for (int i = 0; i < n; i++)
            std::cout << a[i] - mina << ' ';
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
