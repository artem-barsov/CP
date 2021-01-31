#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    int d;
    std::string dish;
    for (int i = 0; i < n-1; i++) {
        std::cin >> d;
        for (int j = 0; j < d; j++) {
            std::cin >> dish;
        }
    }
    std::cin >> d;
    std::cout << d << '\n';
    for (int i = 0; i < d; i++) {
        std::cin >> dish;
        std::cout << dish << '\n';
    }
}
