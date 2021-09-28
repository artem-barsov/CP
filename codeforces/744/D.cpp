#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<std::pair<int, int> > pq;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a) pq.push({a, i});
    }
    std::queue<std::pair<int, int > > qout;
    while (pq.size() > 1) {
        auto [soc1, id1] = pq.top();
        pq.pop();
        auto [soc2, id2] = pq.top();
        pq.pop();
        qout.push({id1, id2});
        if (soc1 > 1) pq.push({soc1 - 1, id1});
        if (soc2 > 1) pq.push({soc2 - 1, id2});
    }
    std::cout << qout.size() << '\n';
    while (!qout.empty()) {
        std::cout << qout.front().first+1 << ' ' << qout.front().second+1 << '\n';
        qout.pop();
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
