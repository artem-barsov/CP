#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int h, w, n;
    std::cin >> h >> w >> n;
    std::vector<std::pair<int, int> > ver(n), hor(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ver[i].first >> hor[i].first;
        ver[i].second = hor[i].second = i;
    }
    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end());
    std::vector<std::pair<int, int> > card(n);
    card[ver[0].second].first = 1;
    for (int i = 1, lvl = 1; i < n; i++) {
        lvl += (ver[i-1].first != ver[i].first);
        card[ver[i].second].first = lvl;
    }
    card[hor[0].second].second = 1;
    for (int i = 1, lvl = 1; i < n; i++) {
        lvl += (hor[i-1].first != hor[i].first);
        card[hor[i].second].second = lvl;
    }
    for (auto& c : card)
        std::cout << c.first << ' ' << c.second << '\n';
}
