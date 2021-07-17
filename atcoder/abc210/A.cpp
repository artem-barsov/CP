#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, a, x, y;
    std::cin >> n >> a >> x >> y;
    std::cout << min(n, a) * x + max(n-a, 0) * y << '\n';
}
