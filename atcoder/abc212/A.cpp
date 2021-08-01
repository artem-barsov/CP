#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int a, b;
    std::cin >> a >> b;
    std::cout << (!a ? "Silver" : (!b ? "Gold" : "Alloy")) << '\n';
}
