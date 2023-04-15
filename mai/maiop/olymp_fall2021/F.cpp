#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int a;
    std::cin >> a;
    int x1, y1, z1;
    int x2, y2, z2;
    int x3, y3, z3;
    std::cin >> x1 >> y1 >> z1;
    std::cin >> x2 >> y2 >> z2;
    std::cin >> x3 >> y3 >> z3;
    int kx =   y1*(z2-z3) + y2*(z3-z1) + y3*(z1-z2) ;
    int ky = -(x1*(z2-z3) + x2*(z3-z1) + x3*(z1-z2));
    int kz =   x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) ;
    int k = -(x1 * kx + y1 * ky + z1 * kz);
    int cnt = 0;
    std::bitset<1 << 3> used;
    for (int bf1 = 0; bf1 < (1 << 3); bf1++) {
        for (int bf2 = bf1; bf2 < (1 << 3); bf2++) {
            int t = bf1 ^ bf2;
            if ((t & (t - 1)) == 0) {
                std::bitset<3> u(bf1);
                std::bitset<3> v(bf2);
                int fu = u[0]*kx*a + u[1]*ky*a + u[2]*kz*a + k;
                int fv = v[0]*kx*a + v[1]*ky*a + v[2]*kz*a + k;
                if (fu == 0) used[bf1] = true;
                if (fv == 0) used[bf2] = true;
                cnt += (fu *1ll* fv < 0);
            }
        }
    }
    std::cout << cnt + used.count() << '\n';
}
