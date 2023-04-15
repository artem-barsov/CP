#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

struct Info { int l, len, cnt; };

const int p = 31;
const int MAX_N = 5 * 1e3 + 1;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    vector<ll> p_pow(MAX_N);
    p_pow[0] = 1;
    for (size_t i = 1; i < p_pow.size(); ++i)
        p_pow[i] = p_pow[i-1] * p;

    std::string s;
    std::cin >> s;
    std::map<ll, Info> hash_info;
    for (int i = 0; i < s.length(); i++) {
        ll hash = 0;
        for (int j = 0; i+j < s.length(); j++) {
    		hash += (s[i+j] - 'a' + 1) * p_pow[j];
            auto it = hash_info.find(hash);
            if (it != hash_info.end())
                it->second.cnt++;
            else
                hash_info[hash] = {i, j+1, 1};
        }
    }
    int max_cost = 0, max_i, max_len;
    for (auto& [hash, info] : hash_info) {
        auto& [i, len, cnt] = info;
        if (max_cost < len * cnt) {
            max_cost = len * cnt;
            max_i = i;
            max_len = len;
        }
        // std::cout << hash << " : " << s.substr(i, len) << " - " << cnt << '\n';
    }
    std::cout << s.substr(max_i, max_len) << '\n';
}
