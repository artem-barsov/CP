#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

enum Player {PANG, SHOU};
struct Rook {
    int x;
    Player player;
    int id;
    friend bool operator< (const Rook& lhs, const Rook& rhs) {
        return (lhs.x < rhs.x);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n1, n2;
    cin >> n1 >> n2;
    vector<bool> ans1(n1, false);
    vector<bool> ans2(n2, false);
    map<int, set<Rook>> figX;
    map<int, set<Rook>> figY;
    int x, y;
    for (int i = 0; i < n1; i++) {
        std::cin >> x >> y;
        figX[y].insert({x, PANG, i});
        figY[x].insert({y, PANG, i});
    }
    for (int i = 0; i < n2; i++) {
        std::cin >> x >> y;
        figX[y].insert({x, SHOU, i});
        figY[x].insert({y, SHOU, i});
    }
    for (auto& [_, line] : figX) {
        auto prev = line.begin();
        for (auto it = std::next(line.begin()); it != line.end(); it++) {
            if (prev->player != it->player) {
                ans1[(prev->player==PANG?prev:it)->id] = true;
                ans2[(prev->player==PANG?it:prev)->id] = true;
            }
            prev = it;
        }
    }
    for (auto& [_, line] : figY) {
        auto prev = line.begin();
        for (auto it = std::next(line.begin()); it != line.end(); it++) {
            if (prev->player != it->player) {
                ans1[(prev->player==PANG?prev:it)->id] = true;
                ans2[(prev->player==PANG?it:prev)->id] = true;
            }
            prev = it;
        }
    }
    for (auto it : ans1) std::cout << it;
    std::cout << '\n';
    for (auto it : ans2) std::cout << it;
    std::cout << '\n';
}
