#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<set<int> > columns(n);
    std::vector<bool> isColumnUnique(n, true);
    int trace = 0, r = 0, c = 0;
    for (int i = 0; i < n; i++) {
        set<int> row;
        bool isUnique = true;
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            if (i == j) trace += x;
            isUnique = row.insert(x).second && isUnique;
            isColumnUnique[j] = columns[j].insert(x).second && isColumnUnique[j];
        }
        r += !isUnique;
    }
    for (int i = 0; i < n; i++) c += !isColumnUnique[i];
    std::cout << trace << ' ' << r << ' ' << c << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
}
