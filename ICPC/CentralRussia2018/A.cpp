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
    int k;
    std::cin >> k;
    unsigned long long sum_a = 0, sum_w = 0;
    for (int i = 0; i < k; i++) {
        int a, w;
        std::cin >> a >> w;
        sum_a += a;
        sum_w += w;
    }
    std::cout << (sum_w % sum_a ? "DEFECT" : "QUALITY") << '\n';
}
