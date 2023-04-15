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
    int n;
    std::cin >> n;
    int a[5] = {0,0,0,0,0};
    for (int i = 0; i < n; i++) {
        int ai;
        std::cin >> ai;
        a[ai]++;
    }
    if (((a[1]+a[3])&1) && ((a[2]+a[3])&1)) {
        if (a[3]) a[3]--;
        else      a[1]--, a[2]--;
    }
    else if ((a[1]+a[3])&1) {
        if (a[1]) a[1]--;
        else      a[3]--, a[2]--;
    }
    else if ((a[2]+a[3])&1) {
        if (a[2]) a[2]--;
        else      a[3]--, a[1]--;
    }
    int ans = 0;
    ans += (a[1]&1) + a[1]/2 + a[2]/2 + a[3]/2 + a[4]/2;
    std::cout << ans << '\n';
}
