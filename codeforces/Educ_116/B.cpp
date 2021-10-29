#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    long long n, k;
    std::cin >> n >> k;
    int t1 = ceil(log2(k));
    long long ost = max(0ll, n - (1ll << t1));
    long long t2 = ceil((double)ost / k);
    std::cout << t1 + t2 << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
