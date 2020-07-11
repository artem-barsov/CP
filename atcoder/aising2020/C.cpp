#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main(int argc, char const *argv[]) {
    ull n;
    std::cin >> n;
    std::map<int, int> f;
    double upp = sqrt(n);
    for (int x = 1; x <= upp; x++) {
        for (int y = 1; y <= upp; y++) {
            for (int z = 1; z <= upp; z++) {
                ull fi = x*x + y*y + z*z + x*y + y*z + z*x;
                if (fi > n) break;
                f[fi]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        std::cout << f[i] << '\n';
}
