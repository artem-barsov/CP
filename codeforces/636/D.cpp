#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    map<int, int> xs;
    for (int i = 0; i < n/2; i++) {
        if ((a[i] > 0) && (a[n-i-1] > 0)) {
            if (a[i] + a[n-i-1] <= 2*k)
                xs[a[i] + a[n-i-1]]++;
        }
    }
    int max_g = 0;
    int x;
    for (auto it : xs) {
        if (max_g < it.second) {
            max_g = it.second;
            x = it.first;
        }
        if (max_g == it.second) {
            x = min(it.first, x);
        }
    }
    int c = 0;
    for (int i = 0; i < n/2; i++) {
        if ((a[i] <= 0) || (a[n-i-1] <= 0)) {
            if (a[i] <= 0) c++;
            if (a[n-i-1] <= 0) c++;
        }
        else if (a[i] + a[n-i-1] != x) {
            if (a[i] + a[n-i-1] >= 2*k) c++;
            if (k - )
            c++;
        }
    }
    std::cout << c << '\n';
}
k=7
6   1   1   7   6   3   4   6
12  5   4   13              +1
int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
