#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ull = unsigned long long;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    ull n;
    cin >> n;
    bitset<61> bn(n);
    vector<int> poss;
    for (int i = 0; i < 62; i++) {
        if (bn[i]) poss.push_back(i);
    }
    // cout << bn << '\n';
    // cout << "bits are : ";
    // for (auto &&x : poss) cout << x << ' ';
    // cout << '\n';
    set<ull> sout;
    for (size_t bf = 0; bf < (1ull << poss.size()); bf++) {
        bitset<16> bs(bf);
        ull x = 0;
        for (int i = 0; i < poss.size(); i++) {
            if (bs[i]) x |= (1ull << poss[i]);
        }
        sout.insert(x);
    }
    for (auto &&x : sout)
        cout << x << '\n';
}