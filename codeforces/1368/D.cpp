#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; i++) std::cin >> a[i];
    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = i; j < n-1; j++) {
            int x = a[j], y = a[j+1];
            a[j] = x & y;
            a[j+1] = x | y;
        }
    }
    ull sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += (ull)a[i]*a[i];
    }
    std::cout << sum << '\n';
}
