#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int l, r, d;
    std::cin >> l >> r >> d;
    std::cout << r/d - ((l-1)/d+1) + 1 << '\n';
}
