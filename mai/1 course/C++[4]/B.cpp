#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, a0;
    std::cin >> n >> a0;
    unsigned long long a = a0, vorletzte=0, letzte=0;
    for (size_t i = 1; i <= n; i++) {
        a = (a * 5) % 1000000007;
        if (a > letzte) {
            vorletzte = letzte;
            letzte = a;
        }
        else vorletzte = max(vorletzte, a);
    }
    std::cout << vorletzte << ' ' << letzte;
}
