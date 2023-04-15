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
    if (n == 2) {
        std::cout << "YES" << '\n';
        printf("%d %d %d %d\n", 7, 10, 5, 12);
        printf("%d %d %d %d\n", 9, 8, 11, 6);
        printf("%d %d %d %d\n", 3, 14, 1, 16);
        printf("%d %d %d %d\n", 13, 4, 15, 2);
    }
    else
        std::cout << "NO" << '\n';
}
