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
    int n, s;
    std::cin >> n >> s;
    std::vector<int> garn(n, INT_MAX);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        garn[a-1] = min(garn[a-1], b);
    }
    sort(garn.begin(), garn.end());
    int cnt = 0;
    while (cnt < n) {
        if (s >= garn[cnt]) {
            s -= garn[cnt];
            cnt++;
        }
        else break;
    }
    std::cout << cnt << '\n';
}
