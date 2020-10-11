#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <tuple>
#include <sstream>

#define OPEN 0
#define CLOSE 1
#define ll long long


using namespace std;

struct Point {
    ll point;
    int type;
    ll sect_index;
    ll len;
};

bool operator < (const Point& lhs, const Point& rhs) {
    if (lhs.point == rhs.point) {
        if (lhs.type == rhs.type) {
            if (lhs.type == OPEN) {
                return lhs.len > rhs.len;
            } else {
                return lhs.len < rhs.len;
            }

        }
        return lhs.type == CLOSE && rhs.type == OPEN;
    }
    return lhs.point < rhs.point;
}

int32_t main() {
    ll n, w;
    cin >> n >> w;
    ll cur_sect = 0;
    vector<Point> points;
    points.reserve(2 * w);
    bool ok = true;
    for (int i = 0; i < w; ++i) {
        ll l, r;
        cin >> l >> r;
        if (l > r) {
            swap(l,r);
        }
        if (abs(l - r) <= 1 || (l == 1 && r == n)) {
            continue;
        }
        points.push_back({l, OPEN, cur_sect, r - l});
        points.push_back({r, CLOSE, cur_sect,  r - l});
        cur_sect++;
    }

    sort(points.begin(), points.end());
    stack<int> last_sec;
    last_sec.push(points.begin()->sect_index);
    for (int i = 1; i < points.size(); ++i) {
        if (points[i].type == OPEN) {
            last_sec.push(points[i].sect_index);
        } else {
            if (last_sec.empty()) {
                ok = false;
                break;
            }
            int last = last_sec.top();
            last_sec.pop();
            if (points[i].sect_index != last) {
                ok = false;
                break;
            }
        }
    }
    if (!ok) {
        cout << "Unsafe\n";
    } else {
        cout << "Safe\n";
    }

    return 0;
}

//8 4
//1 5
//2 4
//2 5
//8 6