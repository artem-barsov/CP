#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::string c;
    std::cin >> n >> c;
    std::vector<int> w(n), r(n);

    w[0] = (c[0] == 'W');
    for (int i = 1; i < n; i++)
        w[i] = w[i-1] + (c[i] == 'W');

    r[n-1] = (c[n-1] == 'R');
    for (int i = n-2; i >= 0; i--)
        r[i] = r[i+1] + (c[i] == 'R');

    int i = 0;
    for (; i < n; i++) {
        if (w[i] > r[i]) break;
    }
    std::cout << w[i-1] << '\n';
}






// int l = 0, r = n-1, cnt = 0;
// while (l < r) {
    //     while (c[l] != 'W') l++;
    //     while (c[r] != 'R') r--;
    //     cnt++;
    //     l++;
    //     r--;
    // }
    // std::cout << cnt << '\n';
