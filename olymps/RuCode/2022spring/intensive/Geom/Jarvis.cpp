#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct vec2 {
    int x, y;
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
bool operator != (const vec2& lhs, const vec2& rhs) {
    return lhs.x != rhs.x || lhs.y != rhs.y;
}
int cross(vec2 a, vec2 b) {
    return a.x*b.y - a.y*b.x;
}
int cross(vec2 a, vec2 b, vec2 c) {
    return cross(b - a, c - a);
}

vec2 rightmost(std::vector<vec2>& p, vec2 t) {
    vec2 ret = p[0];
    // printf("right for (%d %d):\n", t.x, t.y);
    // printf("  now is (%d %d)\n", ret.x, ret.y);
    for (int i = 1; i < p.size(); i++) {
        int cr = cross(t, p[i], ret);
        if (cr > 0
         || cr == 0 && (p[i]-t).sqr_len() > (ret-t).sqr_len()) {
             ret = p[i];
             // printf("  now is (%d %d)\n", ret.x, ret.y);
         }
    }
    return ret;
}

void Jarvis(std::vector<vec2>& p, std::vector<vec2>& conv) {
    sort(p.begin(), p.end(), [&](const vec2& lhs, const vec2& rhs) {
        if (lhs.y != rhs.y)
            return lhs.y < rhs.y;
        return lhs.x < rhs.x;
    });
    vec2 start = p[0], t = rightmost(p, p[0]);
    // printf("start from %d %d\n", start.x, start.y);
    conv.push_back(start);
    while (t != start) {
        conv.push_back(t);
        t = rightmost(p, t);
        // printf("next : %d %d\n", t.x, t.y);
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
    Jarvis(p, conv);
    std::cout << conv.size() << '\n';
    for (auto& q : conv) std::cout << q << '\n';
}
