#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unsigned long long n, m, a, k, mod;
    cin >> n >> m >> a >> k >> mod;
    std::vector<unsigned long long> v(n);
    for (unsigned long long i = 0; i < n; i++) {
        v[i] = a;
        a = (a * m + k) % mod;
    }
    sort(v.begin(), v.end());
    unsigned long long sum = 0;
    for (unsigned long long i = 0; i < n; i++) {
        sum = (sum + (i+1)*v[i]) % 1000000007;
    }
    std::cout << sum;
}
