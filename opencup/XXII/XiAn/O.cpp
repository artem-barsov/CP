#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::vector<int> d1(6), d2(6);
    while (true) {
        for (auto& x : d1) std::cin >> x;
        for (auto& x : d2) std::cin >> x;
        if (cin.eof()) break;
        std::queue<std::pair<std::vector<int>, int> > bfs;
        std::set<std::vector<int> > used;
        bfs.push({d1, 0});
        int ans = -1;
        while (!bfs.empty()) {
            auto [d, step] = bfs.front();
            bfs.pop();
            if (d == d2) {
                ans = step;
                break;
            }
            used.insert(d);
            // Left rotation
            swap(d[0], d[3]); swap(d[1], d[2]); swap(d[2], d[3]);
            if (!used.contains(d)) bfs.push({d, step + 1});
            // Right rotation
            swap(d[0], d[1]); swap(d[2], d[3]);
            if (!used.contains(d)) bfs.push({d, step + 1});
            // Back rotation
            swap(d[0], d[4]); swap(d[1], d[5]); swap(d[2], d[4]); swap(d[3], d[5]);
            if (!used.contains(d)) bfs.push({d, step + 1});
            // Front rotation
            swap(d[0], d[1]); swap(d[4], d[5]);
            if (!used.contains(d)) bfs.push({d, step + 1});
        }
        std::cout << ans << '\n';
    }
}
