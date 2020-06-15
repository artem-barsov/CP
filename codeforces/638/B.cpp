#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    std::cin >> n >> k;
    map<int, int> nums;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        nums[a]++;
    }
    if (nums.size() > k) {
        std::cout << -1 << '\n';
        return;
    }
    std::vector<int> uniq;
    for (auto it : nums) {
        uniq.push_back(it.first);
    }
    std::cout << k * n << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << uniq[j % uniq.size()] << ' ';
        }
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
