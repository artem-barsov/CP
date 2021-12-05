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
    if (k <= n / 2) {
        for (int i = n / 2 + 1; i <= n; i++) {
            std::cout << i << ' ';
            if (!(n&1) || i != n)
                std::cout << i - n / 2 << ' ';
        }
        std::cout << '\n';
    }
    else
        std::cout << "NIE" << '\n';
}
