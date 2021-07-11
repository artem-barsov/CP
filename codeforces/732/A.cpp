#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++) std::cin >> a[i];
    for (size_t i = 0; i < n; i++) std::cin >> b[i];
    int sum = 0;
    queue<int> pos, neg;
    for (size_t i = 0; i < n; i++) {
        int c = a[i] - b[i];
        sum += c;
        if (c > 0) while (c--) pos.push(i);
        else if (c < 0) while (c++) neg.push(i);
    }
    if (sum != 0) {
        std::cout << -1 << '\n';
        return;
    }
    std::cout << pos.size() << '\n';
    while (!pos.empty()) {
        std::cout << pos.front()+1 << ' ' << neg.front()+1 << '\n';
        pos.pop();
        neg.pop();
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
