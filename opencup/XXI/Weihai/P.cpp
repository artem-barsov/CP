#include <iostream>

using namespace std;

int main() {
    int d, l, r, m, c = 0;
    cin >> d >> l >> r;
    while (l < r) {
        ++c;
        m = l + (r - l) / 2;
        if (m == d) break;
        if (m > d) r = m;
        else l = m;
    }
    cout << c << "\n";
}
