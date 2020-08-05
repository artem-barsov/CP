#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int min_a = INT_MAX, min_b = INT_MAX;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        min_a = min(min_a, a[i]);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        min_b = min(min_b, b[i]);
    }
    unsigned long long x = 0;
    for (int i = 0; i < n; i++) {
        int da = a[i] - min_a;
        int db = b[i] - min_b;
        x += da + db - min(da, db);
    }
    std::cout << x << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
