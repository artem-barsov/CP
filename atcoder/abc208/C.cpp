#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
    ull n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++) std::cin >> a[i];
    ull rule1 = k / n;
    std::vector<int> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());
    ull rule2 = sorted_a[k%n - 1];
    for (int id : a)
        std::cout << rule1+(id<=rule2) << '\n';
}
