#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct vec2 {
    long long x, y;
    unsigned long long sqr_len() { return x*x + y*y; }
};
std::istream& operator>> (std::istream& is, vec2& v) {
    return is >> v.x >> v.y;
}
std::ostream& operator<< (std::ostream& os, const vec2& v) {
    return os << v.x << ' ' << v.y;
}
vec2 operator - (const vec2& lhs, const vec2& rhs) {
    return { lhs.x - rhs.x, lhs.y - rhs.y };
}
long long cross(vec2 a, vec2 b) {
    return a.x*b.y - a.y*b.x;
}
long long cross(vec2 a, vec2 b, vec2 c) {
    return cross(b - a, c - a);
}

void Graham(std::vector<vec2>& p, std::vector<vec2>& conv) {
    vec2 start = p[0];
    int idx = 0;
    for (int i = 0; i < p.size(); i++) {
        if (start.y > p[i].y) {
            start = p[i];
            idx = i;
        }
        else if (start.y == p[i].y && start.x > p[i].x) {
            start = p[i];
            idx = i;
        }
    }
    p.erase(p.begin() + idx);
    conv.push_back(start);
    sort(p.begin(), p.end(), [&](const vec2& lhs, const vec2& rhs) {
        long long crs = cross(start, rhs, lhs);
        if (crs != 0)
            return crs > 0;
        return (lhs - start).sqr_len() > (rhs - start).sqr_len();
    });
    conv.push_back(p.back());
    p.pop_back();
    while (!p.empty()) {
        while (conv.size() >= 2 && cross(conv[conv.size()-2], conv.back(), p.back()) <= 0)
            conv.pop_back();
        conv.push_back(p.back());
        p.pop_back();
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    std::cin >> n;
    std::vector<vec2> p(n);
    for (auto& x : p) std::cin >> x;
    std::vector<vec2> conv;
    Graham(p, conv);
    std::cout << conv.size() << '\n';
    for (auto& q : conv) std::cout << q << '\n';
}
