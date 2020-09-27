#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        std::cin >> t;
        int revenue = 0;
        for (int j = 0; j < t; j++) {
            int trans;
            std::cin >> trans;
            int p, q = 1;
            std::cin >> p;
            if (trans == 1) {
                std::cin >> q;
            }
            revenue += p*q;
        }
        printf("Day %d: %d dollars.\n", i, revenue);
    }
}
