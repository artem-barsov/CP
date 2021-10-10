#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

#define NEIN() { std::cout << "Nein" << '\n'; return; }

void solve() {
    int td;
    std::cin >> td;
    int preva, a;
    std::cin >> preva;
    enum Phase { EXPO, ACT, RAZV, POST, NEIN } phase = EXPO;
    std::vector<int> ans;
    for (int i = 0; i < td - 1; i++) {
        std::cin >> a;
        switch (phase) {
        case EXPO:
            if (preva < a) {
                phase = ACT;
                ans.push_back(i);
            }
            if (preva > a) phase = NEIN;
            break;
        case ACT:
            if (preva > a) {
                phase = RAZV;
                ans.push_back(i);
            }
            if (preva == a) phase = NEIN;
            break;
        case RAZV:
            if (preva == a) {
                phase = POST;
                ans.push_back(i);
            }
            if (preva < a) phase = NEIN;
            break;
        case POST:
            if (preva != a) phase = NEIN;
            break;
        }
        preva = a;
    }
    if (ans.size() == 2) ans.push_back(td-1);
    if (phase != RAZV && phase != POST)
        std::cout << "Nein" << '\n';
    else
        std::cout << "Freytag " << ans[0]+1 << ' ' << ans[1]+1 << ' ' << ans[2]+1 << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    std::cin >> t;
    while (t--) solve();
}
