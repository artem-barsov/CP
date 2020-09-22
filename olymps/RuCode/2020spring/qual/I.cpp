#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    std::cin >> n >> k;
    if (k != 0) {
        int f = 1, sum = 1;
        for (int i = 1; i <= min(4, n); i++) {
            f *= i;
            int f_k = f;
            if (k == 2) f_k = f*f;
            if (k == 3) f_k = f*f*f;
            sum += f_k;
            // printf("%d: %d\n", i, sum);
        }
        while (sum % 10 == 0) sum /= 10;
        std::cout << sum % 10 << '\n';
    }
    else {
        n += 1;
        while (n % 10 == 0) n /= 10;
        std::cout << n % 10 << '\n';
    }
}
// k=0
// 0: 1
// 1: 1
// 2: 1
// 3: 1
// 4: 1
//
// k=1
// 0: 1
// 1: 1
// 2: 2
// 3: 6
// 4: 24
//
// k=2
// 0: 1
// 1: 1
// 2: 4
// 3: 36
// 4: 576
//
// k=3
// 0: 1
// 1: 1
// 2: 8
// 3: 216
// 4: 13824
