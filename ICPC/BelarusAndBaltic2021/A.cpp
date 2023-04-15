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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string pat = std::string(k, '1') + std::string(m-k, '0');
    std::string s;
    for (int i = 0; i < n / m; i++)
        s += pat;
    for (int i = 0; s.length() != n; i++)
        s += pat[i];
    std::cout << s << '\n';
}
