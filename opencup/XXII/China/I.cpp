#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long ones = 0, zeros = 0, nigs = 0, poss = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a < 0) nigs++;
        else if (a == 0) zeros++;
        else if (a == 1) ones++;
        else if (a > 0) poss++;
    }
    cout << ones*(n-ones) + ones*(ones-1)/2 + 
            zeros * poss + 
            poss * nigs << '\n';
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