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
    std::vector<std::string> s(n);
    s[0] = std::string(n, 'W');
    bool tob = false;
    for (int i = 1, b = 0; i < n; i++) {
        s[i] = s[i-1];
        s[i][b] = 'B';
        if (!tob) b += 2;
        else b -= 2;
        if (!tob && b >= n) {
            tob = true;
            if (b == n) b = n - 1;
            else b = n - 2;
        }
    }
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (i & 1) std::cout << s[l++] << '\n';
        else       std::cout << s[r--] << '\n';
    }
}
