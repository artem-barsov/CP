#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<std::pair<int, bool> > obj(2 * n); // true - coin
    for (int i = 0; i < n; i++) {
        std::cin >> obj[i].first;
        obj[i].second = false;
    }
    for (int i = n; i < 2*n; i++) {
        std::cin >> obj[i].first;
        obj[i].second = true;
    }
    sort(obj.begin(), obj.end());
    int chest = 0, coins = 0;
    int l = -1, last = 0;
    long long dist = 0;
    for (auto& [coord, isCoin] : obj) {
        if (!isCoin) {
            if (coins == 0) {
                chest++;
                if (l == -1) l = coord;
            }
            else coins--;
// printf("1:coord = %d, dist was = %d, ", coord, dist);
            dist += coord - last;
// printf("dist got = %d\n", dist);
            last = coord;
        }
        else {
            coins++;
// printf("3:coord = %d, dist was = %d, ", coord, dist);
            dist += coord - last;
// printf("dist got = %d\n", dist);
            last = coord;
            if (chest == coins && 2 * (coord - l) < obj.back().first - l) {
                chest = coins = 0;
// printf("2:coord = %d, dist was = %d, ", coord, dist);
                dist += 2 * (coord - l);
// printf("dist got = %d\n", dist);
                last = coord;
                l = -1;
            }
        }
    }
    if (chest) {
// printf("4:coord = %d, dist was = %d, ", l, dist);
        dist += obj.back().first - l;
// printf("dist got = %d\n", dist);
    }
    std::cout << dist << '\n';
}
