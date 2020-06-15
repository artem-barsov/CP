#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unsigned long long n;
    // std::cin >> n;
    scanf("%llu", n);
    unsigned long long res = (1 << n-1);
    // std::cout << res << '\n';
    printf("%llu\n", res);
}
