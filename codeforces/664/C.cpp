#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> b[i];
    int c = 0;
    while (c < (1 << 9)) {
        bool oki = true;
        for (int i = 0; i < n; i++) {
            bool okj = false;
            for (int j = 0; j < m; j++) {
                if (((a[i] & b[j]) | c) == c) {
                    okj = true;
                    break;
                }
            }
            if (!okj) {
                oki = false;
                break;
            }
        }
        if (oki) {
            std::cout << c << '\n';
            break;
        }
        else c++;
    }
}
