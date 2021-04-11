#include <bits/stdc++.h>

using namespace std;

struct vec3d {
    int x, y, z;
};
vec3d operator + (const vec3d & lhs, const vec3d & rhs) {
    return {lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z};
}
vec3d operator - (const vec3d & lhs, const vec3d & rhs) {
    return {lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z};
}
vec3d operator * (const vec3d & a, int n) {
    return {a.x*n, a.x*n, a.x*n};
}
int dot(vec3d a, vec3d b) {
    return a.x*b.x + a.y*b.y;;
}
int cross(vec3d a, vec3d b) {
    return a.x*b.y - a.y*b.x;
}
double lange(vec3d a) { return sqrt(dot(a, a)); }
double distance1(vec3d a, vec3d b) { return lange(a - b); }
double distance_to_line(vec3d p, vec3d q, vec3d a) {
    return abs(cross(p-q, a-p)) / distance1(p, q);
}
double solve() {
    vec3d a, p, q;
    cin >> a.x >> a.y >> p.x >> p.y >> q.x >> q.y;
    return distance_to_line(p, q, a);
}
int main() {
    int n;
    cin >> n;
    cout.setf(ios::scientific);
    cout.precision(12);
    for (int i = 0; i < n; i++) cout << solve() << '\n';
}
