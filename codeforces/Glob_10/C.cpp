#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    ull c = 0;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = n-1; i >= 1; i--)
        c += max(0, a[i-1] - a[i]);
    std::cout << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
