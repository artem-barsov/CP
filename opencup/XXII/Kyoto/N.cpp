#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

bool check(int x) {
    std::string s = to_string(x);
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] + 1 != s[i+1]) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int maprod = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (check(a[i] * a[j]) && maprod < a[i] * a[j]) {
                maprod = a[i] * a[j];
            }
        }
    }
    std::cout << (maprod ? maprod : -1) << '\n';
}
