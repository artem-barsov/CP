#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long n, k;
    std::string s;
    std::cin >> n >> k >> s;
    long long ksum = 0;
    for (size_t i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        ksum += x;
    }
    ksum %= n;
    if (ksum < 0) ksum = n + ksum;
    s = s.substr(ksum, n-ksum) + s.substr(0, ksum);
    std::cout << s << '\n';
}
