#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

struct Team {
    std::string name;
    ll nSolved, pnlt, last;
    Team() = default;
    Team(const std::string& s, ll n, ll p, ll l)
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
    ll n, m, k;
    std::cin >> n >> m >> k;
    std::map<std::string, std::tuple<ll, ll, ll> > db;
    for (ll i = 0; i < m; i++) {
        std::string name;
        std::cin >> name;
        ll nSolved = 0, pnlt = 0, last = 0;
        for (ll j = 0; j < n; j++) {
            char c; ll a, t;
            std::cin >> c >> a >> t;
            if (c == '+') {
                nSolved++;
                pnlt += 20ll * (a - 1) + t;
            }
            if (c != '.') last = max(last, t);
        }
        db[name] = { nSolved, pnlt, last };
    }
    Team top, bot;
    for (ll i = 0; i < k; i++) {
        std::string name;
        std::cin >> name;
        ll nSolved = 0, pnlt = 0, last = 0;
        for (ll j = 0; j < n; j++) {
            char c; ll a, t;
            std::cin >> c >> a >> t;
            if (c == '+') {
                nSolved++;
                pnlt += 20ll * (a - 1) + t;
            }
            if (c != '.') last = max(last, t);
        }
        if (i == 0) top = Team(name, nSolved, pnlt, last);
        if (i == k-1) bot = Team(name, nSolved, pnlt, last);
        db.erase(name);
    }
// std::cout << "top: " << top.name << ' ' << top.nSolved << ' ' << top.pnlt << ' ' << top.last << '\n';
// std::cout << "bot: " << bot.name << ' ' << bot.nSolved << ' ' << bot.pnlt << ' ' << bot.last << '\n';
// for (auto& [name, info] : db) {
//     auto [ns, pn, l] = info;
//     std::cout << name << ' ' << ns << ' ' << pn << ' ' << l << '\n';
// }
    if (m == 1 || m == 2 && k == 1) {
        std::cout << "Leaked" << '\n';
        return 0;
    }
    for (auto& [name, info] : db) {
        auto [ns, pn, l] = info;
        Team x(name, ns, pn, l);
        if (top < x&&x < bot) {
// std::cout << name << " is between " << '\n';
            std::cout << "Fake" << '\n';
            return 0;
        }
    }
    std::cout << "Leaked" << '\n';
}
