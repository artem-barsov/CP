#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, m;
    string a;
    std::cin >> n >> a >> m;
    for (size_t i = 0; i < m; i++) {
        int l;
        std::string b;
        std::cin >> l >> b;
        bool istUnterkette = true;
        int letzte_pos = 0;
        for (size_t j = 0; (j < l) && istUnterkette; j++) {
            for (size_t k = letzte_pos; k < n; k++) {
                if (b[j] == a[k]) {
                    letzte_pos = k+1;
                    break;
                }
                if (k == n-1) istUnterkette = false;
            }
        }
        std::cout << !istUnterkette;
    }
}
