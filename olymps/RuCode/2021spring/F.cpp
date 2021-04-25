#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x;
    bool open;
};
bool operator< (const Point& lhs, const Point& rhs) {
    // if (lhs.x != rhs.x)
    if (!((std::fabs(lhs.x-rhs.x) <= std::numeric_limits<double>::epsilon()*std::fabs(lhs.x+rhs.x)*2)
    || (std::fabs(lhs.x-rhs.x) < std::numeric_limits<double>::min())))
        return lhs.x < rhs.x;
    return lhs.open;
}

int main(int argc, char const *argv[]) {
    int n, r;
    std::cin >> n >> r;
    set<Point> sl;
    for (size_t i = 0; i < n; i++) {
        double x, y;
        std::cin >> x >> y;
        if (abs(y) > r) continue;
        sl.insert({x - sqrt(r*1ull*r - y*1ull*y), true});
        sl.insert({x + sqrt(r*1ull*r - y*1ull*y), false});
    }
    int c = 0, mc = 0;
    for (auto& it : sl) {
        if (it.open)
            mc = max(mc, ++c);
        else
            c--;
    }
    std::cout << mc << '\n';
}
