#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int ones = 0;
    std::vector<int> twos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') twos.push_back(i);
    }
    if (twos.size() == 1 || twos.size() == 2) {
        std::cout << "NO" << '\n';
        return;
    }
    std::vector<std::vector<char> >
        res(n, std::vector<char>(n, '='));
    for (int i = 0; i < n; i++) res[i][i] = 'X';
    if (!twos.empty()) {
        for (int i = 0; i < twos.size()-1; i++) {
            res[twos[i]][twos[i+1]] = '+';
            res[twos[i+1]][twos[i]] = '-';
        }
        res[twos.back()][twos.front()] = '+';
        res[twos.front()][twos.back()] = '-';
    }
    std::cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << res[i][j];
        std::cout << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
