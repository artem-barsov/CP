#include <bits/stdc++.h>

using namespace std;

struct Tsegment {
    long long l, r;
};

struct Tevent {
    long long pos, type;
};

bool operator < (Tevent &lhs, Tevent &rhs) {
    if (lhs.pos != rhs.pos) return lhs.pos < rhs.pos;
    return lhs.type > rhs.type;
}

int main() {
    long long n;
    cin >> n;
    vector<Tsegment> segs;
    vector<Tevent> events;
    for (long long i = 0; i < n; i++) {
        long long inp;
        cin >> inp;
        events.push_back(Tevent{inp, 1});
        cin >> inp;
        events.push_back(Tevent{inp, -1});
    }
    sort(events.begin(), events.end());
    long long ans = 0, cur = 0, pos;
    for (long long i = 0; i < 2*n; i++) {
        cur += events[i].type;
        if (ans < cur) {
            ans = cur;
            pos = events[i].pos;
        }
//        ans = max(ans, cur);
    }
    cout << ans << ' ' << pos;
}
