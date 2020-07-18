#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    bool stinks = false;
    int i = n-1;
    for (i; i > 0; i--) {
        if (a[i-1] < a[i]) stinks = true;
        if (stinks && (a[i-1] > a[i])) break;
    }
    std::cout << i << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
