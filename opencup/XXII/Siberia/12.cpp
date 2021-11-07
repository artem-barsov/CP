#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Coord { double x, y; };

void translateY(std::vector<Coord>& points, int b) {
    for (auto& p : points) p.y += b;
}
void rotate(std::vector<Coord>& points, double rad) {
    for (auto& p : points) {
        double newX = p.x * cos(rad) - p.y * sin(rad);
        double newY = p.x * sin(rad) + p.y * cos(rad);
        p.x = newX;
        p.y = newY;
    }
}
void flipVer(std::vector<Coord>& points, bool d2u) {
    for (auto& p : points) {
        if (d2u ^ (p.y > 0)) p.y = -p.y;
    }
}
void flipHor(std::vector<Coord>& points, bool r2l) {
    for (auto& p : points) {
        if (r2l ^ (p.x < 0)) p.x = -p.x;
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    std::cin >> n >> m;
    std::vector<Coord> points(n);
    for (auto& p : points) std::cin >> p.x >> p.y;
    while (m--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            flipHor(points, (y1 < y2));
        }
        else if (y1 == y2) {
            flipVer(points, (x1 < x2));
        }
        else {
            int dy = y2 - y1;
            int dx = x2 - x1;
            double b = (double)y1 - (double) dy * x1 / (double)dx;
            translateY(points, -b);
            rotate(points, -atan2(dy, dx));
            flipVer(points, true);
            rotate(points, atan2(dy, dx));
            translateY(points, b);
        }
    }
    std::cout << fixed;
    std::cout.precision(11);
    for (auto& p : points)
        std::cout << p.x << ' ' << p.y << '\n';
}
