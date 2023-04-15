#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Graph = vector<vector<int>>;

ll sum(ll a, ll b) {
    return (a + b) * (b - a + 1) / 2;
}

auto main() -> signed {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef DEBUG
    freopen("test", "r", stdin);
#endif

    ll N, K;
    cin >> K >> N;

    if (N == 1) {
        cout << N << '\n';
        return 0;
    }

    double prev_exp = 1.0 * sum(1, N) / N;

    for (int k = 2; k <= K; ++k) {
        ll high_a = ceil(prev_exp - 1e-9), high_b = N;
        ll low_a = 1, low_b = high_a - 1;

        double p1 = ((high_b - high_a + 1.0) / N);
        double p2 = 1.0 - p1;

        double curr_exp = 0;
        if (high_a <= high_b)
            curr_exp += p1 * sum(high_a, high_b) / (high_b - high_a + 1);
        if (low_a <= low_b) curr_exp += p2 * prev_exp;

        prev_exp = curr_exp;
    }

    cout.precision(16);
    cout << prev_exp << endl;

    return 0;
}