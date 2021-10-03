#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

std::string unify(std::string& s) {
    std::set<std::string> uni;
    uni.insert(s);
    for (int i = 0; i < 3; i++) {
        s += s[0];
        s.erase(0, 1);
        uni.insert(s);
    }
    return *uni.begin();
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    std::cin >> k;
    std::multiset<std::string> bars;
    for (int i = 0; i < k; i++) {
        std::string s, l;
        std::cin >> s >> l;
        s += l[1];
        s += l[0];
        bars.insert(unify(s));
    }
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> pic(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pic[i];
    }
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            std::string p = std::string(1, pic[i][j]) + pic[i][j+1]
                                        + pic[i+1][j+1] + pic[i+1][j];
            p = unify(p);
            auto it = bars.find(p);
            if (it != bars.end())
                bars.erase(it);
            else {
                std::cout << "No" << '\n';
                return 0;
            }
        }
    }
    std::cout << "Yes" << '\n';
}
