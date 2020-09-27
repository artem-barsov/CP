#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int l1, r1, l2, r2;
    std::cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (l2 <= r1) std::cout << "1 " << l2;
    else std::cout << "2 " << l1 << ' ' << l2;
 }
