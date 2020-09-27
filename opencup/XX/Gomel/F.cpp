#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    set<int> a;
    for (size_t i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        a.insert(inp);
    }
    int l = 0, r = 0, c;
    for (c = 1; c <= 2*n; c++) {
        if (a.count(c)) l++;
        else r++;
        if ((l == n) || (r == n)) break;
    }
    std::cout << "1 " << (1<<(c-1)) << '\n';
}
