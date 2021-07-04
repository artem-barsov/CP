#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int p;
    std::cin >> p;
    int cost[] = {3628800, 362880, 40320, 5040, 720, 120, 24, 6, 2, 1};
    int c = 0;
    for (int i = 0; i < 10; i++) {
        c += p / cost[i];
        p %= cost[i];
        if (!p) break;
    }
    std::cout << c << '\n';
}
