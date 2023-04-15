#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, k, a, x, y;
    std::cin >> n >> k >> a >> x >> y;
    std::priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        a = (a *1ull* x + y) % (1ull << 30);
        pq.push(a);
        if (pq.size() > k) pq.pop();
    }
    std::vector<int> ans(k);
    for (int i = k - 1; !pq.empty(); i--) {
        ans[i] = pq.top();
        pq.pop();
    }
    for (auto& x : ans) std::cout << x << ' ';
    std::cout << '\n';
}
