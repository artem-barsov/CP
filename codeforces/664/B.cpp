#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, sx, sy;
    std::cin >> n >> m >> sx >> sy;
    std::cout << sx << ' ' << sy << '\n';
    std::cout << 1 << ' ' << sy << '\n';
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (x&1) {
                if ((y == sy) && ((x == 1) || (x == sx))) continue;
                std::cout << x << ' ' << y << '\n';
            }
            else {
                if ((m-y+1 == sy) && ((x == 1) || (x == sx))) continue;
                std::cout << x << ' ' << m-y+1 << '\n';
            }
        }
    }
}
