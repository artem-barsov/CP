#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    int p1 = 0, p2 = 1;
    while (p2 < n) {
        int k1, k2;
        printf("? %d %d\n", p1+1, p2+1);
        // fflush(stdout);
        std::cin >> k1;
        printf("? %d %d\n", p2+1, p1+1);
        // fflush(stdout);
        std::cin >> k2;

        if (k1 > k2) {
            p[p1] = k1;
            p1 = p2;
            p2++;
        }
        else {
            p[p2] = k2;
            p2++;
        }
    }
    std::cout << "! ";
    for (int i = 0; i < n; i++) {
        if (p[i]) std::cout << p[i] << ' ';
        else std::cout << n << ' ';
    }
}
