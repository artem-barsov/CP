#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<unsigned long long> zug(m), ps(m+1);
    for (int i = 0; i < m; i++) {
        std::cin >> zug[i];
        ps[i+1] = ps[i] + zug[i];
    }
    int res = -3;
    while ((res <= m-4) && (ps[res+4]-ps[max(0, res)]<=n)) res++;
    std::cout << max(0, res+2) << '\n';
}
