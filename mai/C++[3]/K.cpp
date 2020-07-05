#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, l;
    std::cin >> n >> l;
    int linkste_r = l, rechste_l = 0;
    for (size_t i = 0; i < n; i++) {
        int p;
        char d;
        cin >> p >> d;
        if (d == 'R') linkste_r = min(linkste_r, p);
        else rechste_l = max(rechste_l, p);
    }
    std::cout << max(rechste_l, l-linkste_r);
}
