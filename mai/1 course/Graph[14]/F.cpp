#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> Baumen(n+1);
    Baumen[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < n; k++) {
            Baumen[i] = (Baumen[i] + Baumen[k] * Baumen[n-k-1]) % m;
        }
    }
    for (size_t i = 0; i <= n; i++) {
        std::cout << Baumen[i] << '\n';
    }
}
