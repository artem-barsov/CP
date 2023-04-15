#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct vec2 { int x, y; };
std::istream& operator>> (std::istream& is, vec2& v) {
    return is >> v.x >> v.y;
}
std::ostream& operator<< (std::ostream& os, const vec2& v) {
    return os << v.x << v.y;
}

vec2 operator - (const vec2& lhs, const vec2& rhs) {
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}
int cross(vec2 a, vec2 b) {
    return a.x*b.y - a.y*b.x;
}
int cross(vec2 a, vec2 b, vec2 c) {
    return cross(b - a, c - a);
}


int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    vec2 a, b, c;
    std::cin >> a >> b >> c;
    vec2 a0 = a, b0 = b;
    n -= 3;
    for (; cross(a, b, c) == 0; n--) {
        if (n == 0) {
            std::cout << "NO" << '\n';
            return 0;
        }
        a = b; b = c;
        std::cin >> c;
    }
    bool toleft = cross(a, b, c) > 0;
    std::queue<vec2> qin;
    while (n--) {
        vec2 inp;
        std::cin >> inp;
        qin.push(inp);
    }
    qin.push(a0);
    qin.push(b0);
    while (!qin.empty()) {
        a = b; b = c;
        c = qin.front();
        qin.pop();
        if (cross(a, b, c) == 0) continue;
        if (toleft == (cross(a, b, c) < 0)) {
            std::cout << "NO" << '\n';
            return 0;
        }
    }
    std::cout << "YES" << '\n';
}
