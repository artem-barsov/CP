#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    map<int, int> a;
    int fours = 0, twos = 0;
    for (int i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        a[inp]++;
        if (a[inp] % 2 == 0) twos++;
        if (a[inp] % 4 == 0) {
            fours++;
            twos -= 2;
        }
    }
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        char act;
        int x;
        std::cin >> act >> x;
        if (act == '+') {
            a[x]++;
            if (a[x] % 4 == 0) {
                fours++;
                twos--;
            }
            else if (a[x] % 2 == 0) twos++;
        }
        else {
            a[x]--;
            if ((a[x]+1) % 4 == 0) {
                fours--;
                twos++;
            }
            else if ((a[x]+1) % 2 == 0) twos--;
        }

        if (fours == 0)         std::cout << "NO" << '\n';
        else if (fours >= 2)    std::cout << "YES" << '\n';
        else if (twos >= 2)     std::cout << "YES" << '\n';
        else                    std::cout << "NO" << '\n';
    }
}
