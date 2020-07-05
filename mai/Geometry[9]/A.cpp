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

double solve() {
    int x, y;
    cin >> x >> y;
    if (atan2(y, x) < 0) return 2*acos(-1) + atan2(y, x);
    return atan2(y, x);
}
int main() {
    int n;
    cin >> n;
    cout.setf(ios::scientific);
    cout.precision(12);
    for (int i = 0; i < n; i++) cout << solve() << endl;
}
