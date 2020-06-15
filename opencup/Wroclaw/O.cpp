#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n;
    std::cin >> m >> n;
    std::map<std::string, map<int, int> > data;
    std::vector<std::string> locations;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::string l;
        std::cin >> a >> b >> l;
        data[l][b]++;
        bool isIn = false;
        for (int j = 0; j < locations.size(); j++)
            if (l == locations[j]) {
                isIn = true;
                break;
            }
        if (!isIn) locations.push_back(l);
    }
    for (int i = 0; i < locations.size(); i++) {
        std::cout << locations[i] << ' ';
        int id, most = 0;
        for (auto & cock : data[locations[i]]) {
            if (cock.second > most) {
                id = cock.first;
                most = cock.second;
            }
        }
        std::cout << id << '\n';
    }
}
