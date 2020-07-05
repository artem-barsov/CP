#include <bits/stdc++.h>
int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    int * a = (int*)malloc(sizeof(int) * (t / 2));
    for (size_t i = 0; i < t; i++) std::cout << a[i] << ' ';
    std::cout << '\n';
}
