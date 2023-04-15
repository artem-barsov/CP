#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define int long long

using namespace std;

struct coord
{
    double x, y;
};

double rad(int deg) {
    return deg * acos(-1) / 180;
}

coord rt(coord a, int deg) {
    a = {-a.x, -a.y};
    double phi = rad(deg);
    return coord{a.x * cos(phi) + a.y * sin(phi), - a.x * sin(phi) + a.y * cos(phi)};
}

coord mv(coord curr, coord norm, int l) {
    return coord{curr.x + norm.x * l, curr.y + norm.y * l};
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for ( auto &it : l) cin >> it;

    vector<int> d(n, 180);
    d[0] = 90;
    for (int i = 0; i < k; i++) {
        int s, a;
        cin >> s >> a;

        d[s] = a;
    }

    coord curr = {0, 0};
    coord norm = {1, 0};
    for (int i = 0; i < n; i++) {
        norm = rt(norm, d[i]);
        curr = mv(curr, norm, l[i]);
    }

    cout.precision(20);
    cout << curr.x << ' ' << curr.y << endl;

}

signed main () {
    cin.tie (nullptr);
    ios::sync_with_stdio (false);

    solve ();

    return 0;
}