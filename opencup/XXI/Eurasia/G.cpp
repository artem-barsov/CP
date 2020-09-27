#include <bits/stdc++.h>

using namespace std;

void solve() {
    int vertices;
    std::cin >> vertices;
    std::vector<std::vector<int>> connections(vertices);
    std::vector<bool> marks(vertices, true);
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            int con = 0;
            std::cin >> con;
            if (i != j && con > 0) {
                connections[i].push_back(j);
                connections[j].push_back(i);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < vertices; ++i) {
        if (marks[i]) {
            std::queue<int> queue;
            queue.push(i);
            marks[i] = false;
            while (!queue.empty()) {
                for (auto j : connections[queue.front()]) {
                    if (marks[j]) {
                        queue.push(j);
                        marks[j] = false;
                        ++res;
                    }
                }
                queue.pop();
            }
        }
    }
    std::cout << res << "\n";
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
