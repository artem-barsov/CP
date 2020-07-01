#include <bits/stdc++.h>

using namespace std;

void pr(std::vector<std::vector<int> >& map) {
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map.size(); j++) {
            printf("%3d", map[i][j]);
            // std::cout << map[i][j] << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int> > map(n, std::vector<int>(n));
    int dc = 0, dr = 0;
    bool fl = true;
    int c = 1;
    while (true) {
        printf("%d:%d\tdr=%d dc=%d c=%d\n", n-1+dr*(fl?1:-1), n-1-dc*(fl?1:-1), dr, dc, c);
        map[n-1+dr*(fl?1:-1)][n-1-dc*(fl?1:-1)] = c++;
        if (--k == 0) goto end;
        pr(map);
        for (int i = max(dr, dc); i < n-1; i++) {
            printf("%d:%d\tdr=%d dc=%d c=%d\n", i+dr*(fl?1:-1), i-dc*(fl?1:-1), dr, dc, c);
            map[i+dr*(fl?1:-1)][i-dc*(fl?1:-1)] = c++;
            if (--k == 0) goto end;
            pr(map);
        }
        if (fl) {
            dr +=  fl;
            dc += !fl;
        }
        else
            swap(dr, dc);
        fl = !fl;
    }
end:
    pr(map);
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
