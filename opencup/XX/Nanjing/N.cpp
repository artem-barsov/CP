#include <bits/stdc++.h>
using namespace std;
size_t digits(array<int,10>& d, size_t n) {
    fill(d.begin(), d.end(), 0);
    if (n == 0) {
        d[0] = 1;
        return 1;
    }
    size_t l = 0;
    while (n > 0) {
        ++l;
        ++d[n % 10];
        n /= 10;
    }
    return l;
}
using namespace std;
int main()
{
    size_t n = 0; cin >> n;
    while (n != 0) {
        array<int, 10> d1, d2, d3;
        size_t l1 = digits(d1, n);
        size_t i = 0, s = 0;
        size_t l2 = digits(d2, s);
        size_t l3 = digits(d3, i);
        cout << "Hidden squares in " << n << '\n';
        while (l2 <= l1) {
            bool ok = true;
            for (int k = 0; k < 10; ++k) {
                ok &= d2[k] <= d1[k];
                ok &= d3[k] <= d1[k];
            }
            if (ok) {
                cout << i << " * " << i << " = " << s << '\n';
            }
            ++i;
            l3 = digits(d3, i);
            s = i * i;
            l2 = digits(d2, s);
        }
        cin >> n;
    }
    return 0;
}
