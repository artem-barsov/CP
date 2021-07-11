#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> v(n), p(n-1);
    for (size_t i = 0; i < n; i++) std::cin >> v[i];
    for (size_t i = 0; i < n-1; i++) std::cin >> p[i];
    std::string ans;
    for (size_t i = 0; i < m; i++) {
        unordered_map<char, int> let;
        for (size_t j = 0; j < n; j++) {
            let[v[j][i]]++;
        }
        for (size_t j = 0; j < n-1; j++) {
            let[p[j][i]]--;
            if (!let[p[j][i]]) let.erase(p[j][i]);
        }
        ans += let.begin()->first;
    }
    std::cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
