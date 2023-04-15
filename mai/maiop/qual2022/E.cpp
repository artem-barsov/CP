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
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    for (int ak = 0, bk = k; ak <= k; ak++, bk--) {
        ans = max(ans, gcd(a-ak, b-bk));
    }
    cout << ans << '\n';
}