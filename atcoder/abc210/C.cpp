#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> c(n);
    for (auto& ci : c) std::cin >> ci;
    std::queue<int> sub;
    std::unordered_map<int, int> candy;
    int cnt = 0, max_cnt = 0;
    for (size_t i = 0; i < k; i++) {
        sub.push(c[i]);
        max_cnt = cnt += !candy[c[i]]++;
    }
    for (size_t i = k; i < n; i++) {
        cnt -= !--candy[sub.front()];
        sub.pop();
        sub.push(c[i]);
        cnt += !candy[c[i]]++;
        max_cnt = max(max_cnt, cnt);
    }
    std::cout << max_cnt << '\n';
}
