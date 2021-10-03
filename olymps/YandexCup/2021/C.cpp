#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    std::cin >> k;
    std::vector<int> a(k), b(k);
    int sum_a = 0;
    for (auto& x : a) {
        std::cin >> x;
        sum_a += x;
    }
    for (auto& x : b) std::cin >> x;

    int upp = 1e5 + 1;
    for (int i = 0; i < k; ++i) {
        if (b[i] != 0) upp = min(upp, a[i] / b[i]);
    }
    while (sum_a % upp != 0) --upp;
    int evr = sum_a / upp;
    std::vector<int> put(k);
    for (int i = 0; i < k; ++i) {
        put[i] = a[i] - b[i] * upp;
    }
    int putt = 0;
    std::cout << upp << ' ' << evr << '\n';
    for (int c = 0; c < upp; ++c) {
        int p = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < b[i]; ++j) {
                std::cout << i + 1 << ' ';
                ++p;
            }
        }
        while (p != evr) {
            while (put[putt] == 0) ++putt;
            ++p;
            --put[putt];
            std::cout << putt + 1 << ' ';
        }
        std::cout << '\n';
    }
}
