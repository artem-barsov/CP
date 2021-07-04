#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    std::cin >> a >> b;
    std::cout << ((a <= b && b <= 6*a) ? "Yes" : "No") << '\n';
}
