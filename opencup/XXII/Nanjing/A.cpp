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
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cout << std::string(n - 1, a <= n / 2 ? 'U' : 'D');
    std::cout << std::string(n - 1, b <= n / 2 ? 'L' : 'R');
    std::cout << (a <= n / 2 ? std::string(a - 1, 'D')
                             : std::string(n - a, 'U'));
    std::cout << (b <= n / 2 ? std::string(b - 1, 'R')
                             : std::string(n - b, 'L'));
    std::cout << '\n';
}
