#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    int n;
    std::cin >> n;
    std::deque<int> deq;
    int a;
    std::cin >> a;
    deq.push_back(a);
    for (int i = 0; i < n-1; i++) {
        std::cin >> a;
        if (a < deq.front())
            deq.push_front(a);
        else
            deq.push_back(a);
    }
    for (auto& x : deq)
        std::cout << x << ' ';
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
