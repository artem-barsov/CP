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
    int m;
    std::cin >> m;
    std::vector<int> a(m);
    for (auto& x : a) std::cin >> x;
    std::vector<int> hist;
    for (int i = 0; i < m;) {
        hist.push_back(a[i]);
        i += a[i];
    }
    for (auto& x : hist) std::cout << x << ' ';
    std::cout << '\n';
}
