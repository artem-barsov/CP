#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Pl { int l, r; };

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    n = (1 << n);
    std::map<std::string, int> name2id;
    for (int i = 0; i < n; i++) {
        std::string name;
        std::cin >> name;
        name2id[name] = i;
    }
    std::vector<Pl> players(n);
    std::set<int> playing;
    for (int i = 0; i < n; i++) {
        players[i] = {i, i};
        playing.insert(i);
    }
    std::string games;
    std::cin >> games;
    int g = 0;
    for (int i = (n >> 1); i >= 1; i >>= 1) {
        auto p1 = playing.begin();
        auto p2 = std::next(p1);
        for (int j = 0; j < i; j++, g++) {
            std::set<int>::iterator todel;
            if (games[g] == 'W') {
                players[*p1].r = players[*p2].r;
                todel = p2;
            }
            else {
                players[*p2].l = players[*p1].l;
                todel = p1;
            }
            std::advance(p1, 2);
            std::advance(p2, 2);
            playing.erase(todel);
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        std::string name1, name2;
        std::cin >> name1 >> name2;
        int id1 = name2id[name1];
        int id2 = name2id[name2];
        if (players[id1].l <= id2&&id2 <= players[id1].r)
            std::cout << "Win" << '\n';
        else if (players[id2].l <= id1&&id1 <= players[id2].r)
            std::cout << "Lose" << '\n';
        else
            std::cout << "Unknown" << '\n';
    }
}
