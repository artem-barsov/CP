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
double lange(vec3d a) { return sqrt(dot(a, a)); }
double solve() {
    vec3d p0, p1, p2;
    cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y;
    vec3d a = p1-p0, b = p2-p0;
    return acos(dot(a, b) / (lange(a) * lange(b)));
}
int main() {
    int n;
    cin >> n;
    cout.setf(ios::scientific);
    cout.precision(12);
    for (int i = 0; i < n; i++) cout << solve() << endl;
}
