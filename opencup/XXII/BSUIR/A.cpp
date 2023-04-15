#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ull = unsigned long long;

const int MOD = 1e9 + 7;

// fib[2] = 1
// fib[1000000006] = 1

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ull n;
    // std::cin >> n;
    // std::vector<int> fib = {0, 1};
    int a = 0, b = 1;
    int cnt = 0;
    for (int i = 2; ; i++) {
        // fib.push_back((fib[i-2] + fib[i-1]) % MOD);
        int c = (a + b) % MOD;
        a = b; b = c;
        if (cnt) {
            // printf("fib[%d] = %d\n", i, fib[i]);
            printf("fib[%d] = %d\n", i, b);
            cnt--;
        }
        if (fib[i] == 1) {
            // printf("fib[%d] = %d\n", i, fib[i]);
            printf("fib[%d] = %d\n", i, b);
            cnt = 10;
        }
    }

}
