#include <bits/stdc++.h>

using namespace std;

struct Tele { int x, l, r, id; };
bool operator< (const Tele& lhs, const Tele& rhs) {
    if (lhs.x != rhs.x)
        return lhs.x < rhs.x;
    return lhs.id < rhs.id;
}

struct Point { int x, id; };
bool operator< (const Point& lhs, const Point& rhs) {
    if (lhs.x != rhs.x)
        return lhs.x < rhs.x;
    return lhs.id < rhs.id;
}

void srch(std::queue<std::pair<Tele, int> >& bfs, std::set<Tele>& t,
std::set<Point>& p, std::vector<int>& visit, int step, int l, int r) {
    auto lp = p.lower_bound({l, -1});
    auto rp = p.upper_bound({r, INT_MAX});
    while (lp != rp) {
        visit[lp->id] = step + 1;
        auto todel = lp;
        lp++;
        p.erase(todel);
    }
    auto lt = t.lower_bound({l, 42, 42, -1});
    auto rt = t.upper_bound({r, 42, 42, INT_MAX});
    while (lt != rt) {
        bfs.push({*lt, step + 1});
        auto todel = lt;
        lt++;
        t.erase(todel);
    }
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::set<Tele> t;
    Tele t0;
    std::cin >> t0.x >> t0.l >> t0.r;
    t0.id = 0;
    for (int i = 1; i < n; i++) {
        Tele tmp;
        std::cin >> tmp.x >> tmp.l >> tmp.r;
        tmp.id = i;
        t.insert(tmp);
    }
    int m;
    std::cin >> m;
    std::set<Point> p;
    for (int i = 0; i < m; i++) {
        Point tmp;
        std::cin >> tmp.x;
        tmp.id = i;
        p.insert(tmp);
    }
    std::queue<std::pair<Tele, int> > bfs;
    std::vector<int> visit(m, -1);
    bfs.push({t0, 0});
    srch(bfs, t, p, visit, -1, bfs.front().first.x, bfs.front().first.x);
    while (!bfs.empty() && !p.empty()) {
        auto [u, step] = bfs.front();
        bfs.pop();
        srch(bfs, t, p, visit, step, u.x-u.r, u.x-u.l);
        srch(bfs, t, p, visit, step, u.x+u.l, u.x+u.r);
    }
    for (auto& x : visit) std::cout << x << ' ';
    std::cout << '\n';
}
