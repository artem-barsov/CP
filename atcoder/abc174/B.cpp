#include <bits/stdc++.h>

using namespace std;

struct TPoint {
    long long x, y;
};

long long sqr(long long a) {
    return a*a;
}

int main(int argc, char const *argv[]) {
    long long n, d;
    std::cin >> n >> d;
    std::vector<TPoint> p(n);
    for (int i = 0; i < n; i++)
        std::cin >> p[i].x >> p[i].y;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (sqr(p[i].x) + sqr(p[i].y) <= sqr(d)) c++;
    }
    std::cout << c << '\n';
}
