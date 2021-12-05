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
    int n, m;
    std::cin >> n >> m;
    std::string s[] = { std::string(m, '.'), std::string(m, '#') };
    for (int i = 0; i < n; i++) {
        std::cout << s[i & 1] << '\n';
    }
}
