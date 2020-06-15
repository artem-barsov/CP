#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long xc, yc, r, x0, y0, t;
    std::cin >> t;
    for (long long i = 0; i < t; i++) {
        std::cin >> xc >> yc >> r >> x0 >> y0;
        long long xn, yn;
        queue<pair<long long, long long> > bfs;
        while (!bfs.empty()) bfs.pop();
        bool isOut = false;
        if ((xc > x0) && (yc > y0)) {
            // xn = max(x0, xc-r);
            // yn = max(y0, yc-r);
            xn = x0; yn = y0;
            bfs.push({xn, yn});
            while ((xn-xc)*(xn-xc)+(yn-yc)*(yn-yc) > (r*r)) {
                isOut = true;
                xn = bfs.front().first;
                yn = bfs.front().second;
                bfs.push({xn, yn+1});
                bfs.push({xn+1, yn});
                bfs.pop();
            }
        }
        else if ((xc < x0) && (yc > y0)) {
            // xn = min(x0, xc+r);
            // yn = max(y0, yc-r);
            xn = x0; yn = y0;
            bfs.push({xn, yn});
            while ((xn-xc)*(xn-xc)+(yn-yc)*(yn-yc) > (r*r)) {
                isOut = true;
                xn = bfs.front().first;
                yn = bfs.front().second;
                bfs.push({xn, yn+1});
                bfs.push({xn-1, yn});
                bfs.pop();
            }
        }
        else if ((xc < x0) && (yc < y0)) {
            // xn = min(x0, xc+r);
            // yn = min(y0, yc+r);
            xn = x0; yn = y0;
            bfs.push({xn, yn});
            while ((xn-xc)*(xn-xc)+(yn-yc)*(yn-yc) > (r*r)) {
                isOut = true;
                xn = bfs.front().first;
                yn = bfs.front().second;
                bfs.push({xn, yn-1});
                bfs.push({xn-1, yn});
                bfs.pop();
            }
        }
        else if ((xc > x0) && (yc < y0)) {
            // xn = min(x0, xc+r);
            // yn = min(y0, yc+r);
            xn = x0; yn = y0;
            bfs.push({xn, yn});
            while ((xn-xc)*(xn-xc)+(yn-yc)*(yn-yc) > (r*r)) {
                isOut = true;
                xn = bfs.front().first;
                yn = bfs.front().second;
                bfs.push({xn, yn-1});
                bfs.push({xn+1, yn});
                bfs.pop();
            }
        }
        else {
            if (x0 == xc) {
                if (yc > y0) {
                    if (y0 < yc-r) {
                        isOut = true;
                        yn = yc - r;
                    } else yn = y0;
                } else {
                    if (y0 > yc+r) {
                        isOut = true;
                        yn = yc + r;
                    } else yn = y0;
                }
                xn = x0;
            } else if (y0 == yc) {
                if (xc > x0) {
                    if (x0 < xc-r) {
                        isOut = true;
                        xn = xc - r;
                    } else xn = x0;
                } else {
                    if (x0 > xc+r) {
                        isOut = true;
                        xn = xc + r;
                    } else xn = x0;
                }
                yn = y0;
            }
        }
        if (isOut) std::cout << 1 << '\n' << x0 << ' ' << y0 << ' ' << xn << ' ' << yn << '\n';
        else std::cout << 0 << '\n' << x0 << ' ' << y0 << '\n';
    }
}
