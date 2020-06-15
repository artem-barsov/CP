#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct T {
    int val, pow;
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, p;
    std::cin >> n >> m >> p;
    T a;
    for (int i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        if ((inp % p) != 0) a = {inp, i};
    }
    T b;
    for (int i = 0; i < m; i++) {
        int inp;
        std::cin >> inp;
        if ((inp % p) != 0) b = {inp, i};
    }
    std::cout << a.pow + b.pow << '\n';
}
