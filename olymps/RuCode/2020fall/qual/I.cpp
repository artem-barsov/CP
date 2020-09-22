#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::map<int, int> a;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        ++a[inp];
        m = max(m, a[inp]);
    }
    std::cout << m << '\n';
}
