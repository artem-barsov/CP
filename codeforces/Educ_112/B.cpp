#include <bits/stdc++.h>

using namespace std;

struct Fig { int w, h; };

Fig intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int l = max(x1, x3);
    int r = min(x2, x4);
    int b = max(y1, y3);
    int t = min(y2, y4);
    int w = r - l;
    int h = t - b;
    return {max(0, w), max(0, h)};
}

#define tor (p[2] - x1)
#define tot (p[3] - y1)
#define tob (y2 - p[1])
#define tol (x2 - p[0])

void solve() {
    int W, H;
    int x1, y1, x2, y2;
    int w, h;
    std::cin >> W >> H;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cin >> w >> h;
    int ans = INT_MAX;
    { // left-bottom
        int p[] = { 0, 0, w, h };
        auto [cx, cy] = intersect(x1, y1, x2, y2, p[0], p[1], p[2], p[3]);
        if (!cx || !cy) ans = 0;
        if (cx && tor <= W-x2) ans = min(ans, tor);
        if (cy && tot <= H-y2) ans = min(ans, tot);
    }
    { // left-top
        int p[] = { 0, H-h, w, H };
        auto [cx, cy] = intersect(x1, y1, x2, y2, p[0], p[1], p[2], p[3]);
        if (!cx || !cy) ans = 0;
        if (cx && tor <= W-x2) ans = min(ans, tor);
        if (cy && tob <= y1) ans = min(ans, tob);
    }
    { // right-top
        int p[] = { W-w, H-h, W, H };
        auto [cx, cy] = intersect(x1, y1, x2, y2, p[0], p[1], p[2], p[3]);
        if (!cx || !cy) ans = 0;
        if (cx && tol <= x1) ans = min(ans, tol);
        if (cy && tob <= y1) ans = min(ans, tob);
    }
    { // right-bottom
        int p[] = { W-w, 0, W, h };
        auto [cx, cy] = intersect(x1, y1, x2, y2, p[0], p[1], p[2], p[3]);
        if (!cx || !cy) ans = 0;
        if (cx && tol <= x1) ans = min(ans, tol);
        if (cy && tot <= H-y2) ans = min(ans, tot);
    }
    std::cout << (ans != INT_MAX ? ans : -1) << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
