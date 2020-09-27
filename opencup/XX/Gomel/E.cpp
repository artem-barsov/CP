#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    double koef = 0;
    for (size_t i = 0; i <= k; i++) {
        double prob;
        std::cin >> prob;
        koef += i*prob;
    }
    printf("%lf\n", n * koef);
}
