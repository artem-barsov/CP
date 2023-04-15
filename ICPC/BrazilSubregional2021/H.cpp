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
    int n, k;
    std::cin >> n >> k;
    std::vector<std::priority_queue<int,
                std::vector<int>, std::greater<int> > > group(k);
    std::vector<int> clr(n, -1);
    for (int i = 0; i < n; i++) {
        int x, c;
        std::cin >> x >> c;
        x--; c--;
        clr[i] = c;
        group[c].push(x);
    }
    for (int i = 0; i < n; i++) {
        if (group[clr[i]].top() == i) group[clr[i]].pop();
        else {
            std::cout << "N" << '\n';
            return 0;
        }
    }
    std::cout << "Y" << '\n';
}
