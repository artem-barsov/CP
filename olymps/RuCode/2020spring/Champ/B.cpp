#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int a[4], t;
    for (int i = 0; i < 4; i++) std::cin >> a[i];
    std::cin >> t;
    if (t == 1) {
        sort(&a[0], &a[4]);
        if (a[3] < a[0] + a[1] + a[2])
            std::cout << 1 << '\n';
        else
            std::cout << 0 << '\n';
    }
    else if (t == 2) {
        sort(&a[0], &a[4]);
        if ((a[3] < a[0] + a[1] + a[2]) && !((a[0] == a[1])&&(a[1] == a[2])&&(a[2] == a[3])&&(a[3] == a[0])))
            std::cout << 1 << '\n';
        else
            std::cout << 0 << '\n';
    }
    else if (t == 3) {
        sort(&a[0], &a[4]);
        if ((a[0] == a[1]) && (a[2] == a[3]))
            std::cout << 1 << '\n';
        else
            std::cout << 0 << '\n';
    }
    else if (t == 4) {
        if ((a[0] == a[1])&&(a[1] == a[2])&&(a[2] == a[3])&&(a[3] == a[0]))
            std::cout << 1 << '\n';
        else
            std::cout << 0 << '\n';
    }
}
