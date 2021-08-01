#include <bits/stdc++.h>

using namespace std;

struct T {
    int val;
    bool arr;
};

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<T> a(n + m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].val;
        a[i].arr = false;
    }
    for (int i = n; i < n+m; i++) {
        std::cin >> a[i].val;
        a[i].arr = true;
    }
    sort(a.begin(), a.end(), [&](const T& lhs, const T& rhs) {
        return lhs.val < rhs.val;
    });
    int ans = INT_MAX;
    for (int i = 0; i < n+m-1; i++) {
        if (a[i].arr ^ a[i+1].arr) {
            ans = min(ans, a[i+1].val - a[i].val);
        }
    }
    std::cout << ans << '\n';
}
