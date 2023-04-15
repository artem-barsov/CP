#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

// 1 2 3 5 8 13 21 34 55 89 144

vector<int> fib = {1, 2};

void solve() {
    int n;
    cin >> n;
    cout << n - distance(fib.begin(), upper_bound(fib.begin(), fib.end(), n)) << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    while (fib.back() < 1e9)
        fib.push_back(fib[fib.size()-2]+fib[fib.size()-1]);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}