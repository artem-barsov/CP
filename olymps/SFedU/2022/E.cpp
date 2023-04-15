#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

#define watch(x) std::cout << #x << " = " << x << '\n';

using namespace std;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ull a, b, n;
    std::cin >> a >> b >> n;

    ull hc = a / n;
    ull hb;
    if (hc & 1)
        hb = n * (hc / 2 + 1);
    else
        hb = n * hc / 2 + a % n;
    ull hw = a - hb;

    ull vc = b / n;
    ull vb;
    if (vc & 1)
        vb = n * (vc / 2 + 1);
    else
        vb = n * vc / 2 + b % n;
    ull vw = b - vb;

    // watch(hc); watch(hb); watch(hw); watch(vc); watch(vb); watch(vw);
    std::cout << vb * hb + vw * hw << '\n';
}
