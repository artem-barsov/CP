#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Peak {
    int id, sum;
};

void solve() {
    int n, k;
    std::cin >> n >> k;
    int a, b, c;
    std::cin >> a >> b;
    queue<int> peaks;
    std::vector<Peak> cum;
    for (int i = 2; i < n; i++) {
        std::cin >> c;
        if ((a < b) && (b > c)) {
            peaks.push(i-1);
            while (i - k + 1 >= peaks.front()) peaks.pop();
            cum.push_back(Peak{i-1, (int)peaks.size()});
        }
        a = b;
        b = c;
    }

    int max_sum = 0, l = 0;
    for (int i = 0; i < cum.size(); i++) {
        if (max_sum < cum[i].sum) {
            max_sum = cum[i].sum;
            l = cum[i].id - k + 2;
        }
    }
    std::cout << max_sum + 1 << ' ' << max(0, l) + 1 << '\n';
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
