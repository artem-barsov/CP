#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

const double EPS = 1E-9;

struct pt {
	double x, y;
    bool operator< (const pt & p) const {
		return x < p.x-EPS || abs(x-p.x) < EPS && y < p.y - EPS;
	}
};

struct line {
	double a, b, c;
	line() {}
	line (pt p, pt q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		norm();
	}
	void norm() {
		double z = sqrt (a*a + b*b);
		if (abs(z) > EPS)
			a /= z,  b /= z,  c /= z;
	}
    double dist (pt p) const {
		return a * p.x + b * p.y + c;
	}
};

#define det(a,b,c,d)  (a*d-b*c)

inline bool betw (double l, double r, double x) {
	return min(l,r) <= x + EPS && x <= max(l,r) + EPS;
}

inline bool intersect_1d (double a, double b, double c, double d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max (a, c) <= min (b, d) + EPS;
}

bool intersect (pt a, pt b, pt c, pt d, pt & left, pt & right) {
	if (! intersect_1d (a.x, b.x, c.x, d.x) || ! intersect_1d (a.y, b.y, c.y, d.y))
		return false;
	line m (a, b);
	line n (c, d);
	double zn = det (m.a, m.b, n.a, n.b);
	if (abs (zn) < EPS) {
		if (abs (m.dist (c)) > EPS || abs (n.dist (a)) > EPS)
			return false;
		if (b < a)  swap (a, b);
		if (d < c)  swap (c, d);
		left = max (a, c);
		right = min (b, d);
		return true;
	}
	else {
		left.x = right.x = - det (m.c, m.b, n.c, n.b) / zn;
		left.y = right.y = - det (m.a, m.c, n.a, n.c) / zn;
		return betw (a.x, b.x, left.x)
			&& betw (a.y, b.y, left.y)
			&& betw (c.x, d.x, left.x)
			&& betw (c.y, d.y, left.y);
	}
}

double dist(pt a, pt b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, m;
    cin >> n >> m;
    vector<tuple<line, pt, pt>> polygon;
    polygon.reserve(n);
    double x0, y0;
    cin >> x0 >> y0;
    double prevx = x0, prevy = y0;
    double ans = 0;
    for (int i = 0; i < n-1; i++) {
        double xi, yi;
        cin >> xi >> yi;
        polygon.emplace_back(line(pt(prevx, prevy), pt(xi, yi)), pt(prevx, prevy), pt(xi, yi));
        ans += dist(pt(prevx, prevy), pt(xi, yi));
        prevx = xi;
        prevy = yi;
    }
    polygon.emplace_back(line(pt(prevx, prevy), pt(x0, y0)), pt(prevx, prevy), pt(x0, y0));
    ans += dist(pt(prevx, prevy), pt(x0, y0));
    cin >> prevx >> prevy;
    for (int i = 0; i < m-1; i++) {
        int xi, yi;
        cin >> xi >> yi;
        line l(pt(prevx, prevy), pt(xi, yi));
        vector<pt> inter_p;
        for (auto &&[pl, ll, lr] : polygon) {
            pt p;
            if (intersect(pt(prevx, prevy), pt(xi, yi), ll, lr, p, p))
                inter_p.push_back(p);
        }
        prevx = xi;
        prevy = yi;
        // sort(inter_p.begin(), inter_p.end(), [&](const pt& lhs, const pt& rhs) {
        //     return tie(lhs.x, lhs.y) < tie(rhs.x, rhs.y);
        // });
        for (int i = 0; i < inter_p.size(); i += 2) {
            ans += 2 * dist(inter_p[i], inter_p[i+1]);
        }
        // cout << "intersected in : ";
        // for (auto &&[x, y] : inter_p) {
        //     cout << "(" << x << ";" << y << "), ";
        // }
        // cout << '\n';
    }
    cout << ans << '\n';
}