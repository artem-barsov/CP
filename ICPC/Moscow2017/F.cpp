#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Team {
    std::string name;
    int nSolved, pnlt, last;
    Team(const std::string& s, int n, int p, int l)
        : name(s), nSolved(n), pnlt(p), last(l) { }
};
bool operator< (const Team& lhs, const Team& rhs) {
    if (lhs.nSolved != rhs.nSolved)
        return lhs.nSolved > rhs.nSolved;
    if (lhs.pnlt != rhs.pnlt)
        return lhs.pnlt < rhs.pnlt;
    if (lhs.last != rhs.last)
        return lhs.last < rhs.last;
    return lhs.name < rhs.name;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m, k;
    std::cin >> n >> m >> k;
    std::set<Team> sb;
    std::map<std::string, std::tuple<int, int, int> > db;
    for (int i = 0; i < m; i++) {
        int nSolved = 0, pnlt = 0, last = 0;
        std::string name;
        std::cin >> name;
        for (int j = 0; j < n; j++) {
            char c; int a, t;
            std::cin >> c >> a >> t;
            if (c == '+') {
                nSolved++;
                pnlt += 20 * (a - 1) + t - 1;
            }
            if (c != '.') last = max(last, t);
        }
        sb.emplace(name, nSolved, pnlt, last);
        db[name] = { nSolved, pnlt, last };
    }
// std::cout << "---------------------------------" << '\n';
// std::cout << "sb frozen: " << '\n';
// for (auto& [name, nS, pn, l] : sb) {
//     std::cout << name << ": " << nS << ' ' << pn << ' ' << l << '\n';
// }
// std::cout << "---------------------------------" << '\n';
    std::vector<std::string> order(k);
    for (int i = 0; i < k; i++) {
        int nSolved = 0, pnlt = 0, last = 0;
        std::string name;
        std::cin >> name;
        for (int j = 0; j < n; j++) {
            char c; int a, t;
            std::cin >> c >> a >> t;
            if (c == '+') {
                nSolved++;
                pnlt += 20 * (a - 1) + t - 1;
            }
            if (c != '.') last = max(last, t);
        }
        auto [nS, pn, l] = db[name];
        sb.erase({ name, nS, pn, l });
        sb.emplace(name, nSolved, pnlt, last);
        db[name] = { nSolved, pnlt, last };
        order[i] = name;
    }
// std::cout << "---------------------------------" << '\n';
// std::cout << "sb after: " << '\n';
// for (auto& [name, nS, pn, l] : sb) {
//     std::cout << name << ": " << nS << ' ' << pn << ' ' << l << '\n';
// }
// std::cout << "---------------------------------" << '\n';
// std::cout << "order: ";
// for (auto& x : order) { std::cout << x << ' '; }
// std::cout << '\n';
    auto [nS, pn, l] = db[order[0]];
    auto it = sb.find({ order[0], nS, pn, l });
    if (m == 1 || m == 2 && k == 1) {
        std::cout << "Leaked" << '\n';
        return 0;
    }
// std::cout << "it: " << it->name << ' ' << it->nSolved << ' ' << it->pnlt << ' ' << it->last << '\n';
    for (int i = 1; i < k; i++) {
        it++;
        if (it == sb.end() || order[i] != it->name) {
            std::cout << "Fake" << '\n';
            return 0;
        }
    }
    std::cout << "Leaked" << '\n';
}
