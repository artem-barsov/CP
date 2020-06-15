#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

// const int X = 13;
//

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n = 1e6;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (long long i = 2; i <= n; ++i) {
        if (prime[i]) {
            if (i * 1ll * i <= n)
                for (long long j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
        }
    }

    vector<long long> v;
    // тут поменять n на загаданное число шобы не циклить как лох
    for (long long i = 2; i <= 20; ++i) {
        if (!prime[i]) {
            continue;
        }

        cout << "? " << i << endl;
        cout.flush();

        // long long g = gcd(i, X);
        long long g;

        cin >> g;
        if (g == i) {
            v.push_back(i);
        }
    }

    long long ans = 1;
    for (long long i = 0; i < v.size(); ++i) {
        long long l = 1;
        long long r = 2;
        long long last = v[i];
        while (pow(v[i], r) < 1e6) {
            ++r;
        }

        while (l < r) {
            long long m = (l + r) / 2;
            long long cur = pow(v[i], m);
            cout << "? " << cur << endl;
            // long long g = gcd(X, cur);
            long long g;
            cin >> g;

            if (g == cur) {
                l = m;
                last = cur;
            } else {
                r = m-1;
            }
        }

        ans *= last;
    }
    cout << ans << endl;

    return 0;
}
