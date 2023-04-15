#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct Coord {
    int x, y;
    int lenlen() { return x*x + y*y; }
};
istream& operator>>(istream& is, Coord& c) { return is >> c.x >> c.y; }
int operator*(const Coord& lhs, const Coord& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    if (n == 3) {
        Coord p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        Coord v1 = {p1.x - p2.x, p1.y - p2.y};
        Coord v2 = {p2.x - p3.x, p2.y - p3.y};
        Coord v3 = {p3.x - p1.x, p3.y - p1.y};
        if (v1*v2 == 0 || v2*v3 == 0 || v3*v1 == 0)
            cout << 2 << '\n'; // прямоугольный треугольник
        else {
            int t = 0;
            if (v1*v2 < 0) t++;
            if (v2*v3 < 0) t++;
            if (v3*v1 < 0) t++;
            if (t == 1 || t == 2)
                cout << 3 << '\n'; // тупоугольный треугольник
            else
                cout << 1 << '\n'; // остроугольный треугольник
        }
    }
    else {
        Coord p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;
        Coord v1 = {p1.x - p2.x, p1.y - p2.y};
        Coord v2 = {p2.x - p3.x, p2.y - p3.y};
        Coord v3 = {p3.x - p4.x, p3.y - p4.y};
        Coord v4 = {p4.x - p1.x, p4.y - p1.y};
        if (v1.lenlen() == v2.lenlen() && v2.lenlen() == v3.lenlen() && v3.lenlen() == v4.lenlen()) {
            if (v1*v2 == 0 && v2*v3 == 0 && v3*v4 == 0 && v4*v1 == 0)
                cout << 8 << '\n'; // квадрат
            else
                cout << 6 << '\n'; // ромб
        }
        else if (v1.lenlen() == v3.lenlen() && v2.lenlen() == v4.lenlen()) {
            if (v1*v2 == 0 && v2*v3 == 0 && v3*v4 == 0 && v4*v1 == 0)
                cout << 7 << '\n'; // прямоугольник
            else
                cout << 4 << '\n'; // параллелограмм
        }
        else
            cout << 5 << '\n'; // трапеция
    }
}