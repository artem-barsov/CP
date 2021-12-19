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
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    if (b*d*f == a*c*e
     && b*d < (a + b)*c
     && b*d > (a-b)*c
     && b*d > (b-a)*c  ) {
        std::cout << 1 << '\n';
    }
    else
        std::cout << -1 << '\n';
}
