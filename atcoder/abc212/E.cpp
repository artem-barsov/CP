#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int> > mtx(n, std::vector<int>(n, 1));
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        mtx[u][v] = 0;
        mtx[v][u] = 0;
    }
    for (int i = 0; i < n; i++) mtx[i][i] = 0;
    std::vector<ull> d(n);
    for (int i = 0; i < n; i++) d[i] = mtx[0][i];
// printf("%d: ",1);for(int x:d)std::cout<<x<<'\t';std::cout<<'\n';
    for (int i = 0; i < k-1; i++) {
        std::vector<ull> dk(n);
        for (int j = 0; j < n; j++) {
            ull sum = 0;
            for (int p = 0; p < n; p++) {
                sum = (sum + d[p] * mtx[p][j]) % 998244353;
            }
            dk[j] = sum;
        }
        d.swap(dk);
// printf("%d: ",i+2);for(int x:d)std::cout<<x<<'\t';std::cout<<'\n';
    }
    std::cout << d[0] << '\n';
}
