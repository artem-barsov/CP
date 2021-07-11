#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> even, odd;
    for (size_t i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (i&1) odd.push_back(a);
        else even.push_back(a);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    std::vector<int> a;
    for (size_t i = 0; i < even.size(); i++) {
        a.push_back(even[i]);
        if (i < odd.size())
            a.push_back(odd[i]);
    }
    for (size_t i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            std::cout << "NO" << '\n';
            return;
        }
    }
    std::cout << "YES" << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
