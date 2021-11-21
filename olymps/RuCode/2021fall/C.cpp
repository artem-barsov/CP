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
    int n, k;
    std::cin >> n >> k;
    std::vector<char> used(n, false);
    int cnt_max = 0, cnt_min = 0;
    for (int i = 0; i < k; i++) {
        int a;
        std::cin >> a;
        if (used[a-1]) cnt_max++;
        else cnt_min++;
        used[a-1] = true;
    }
    std::cout << cnt_min << '\n';
    std::cout << n - cnt_max << '\n';
}
