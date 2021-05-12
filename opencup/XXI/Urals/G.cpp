#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

struct node {
    int a;
    int b;
    int c;
};

int main() {
    int m, g, n;
    cin >> m >> g >> n;
    vector<node> v(n);
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    for (int i = 0; i < n; ++i) {
        cin >> v[i].a;
        cin >> v[i].b;
        cin >> v[i].c;
    }
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= g; ++j) {
            for (int k = 0; k < n; ++k) {
                if (v[k].a > i) continue;
                if (v[k].b > j) continue;
                dp[i][j] = max(dp[i][j], dp[i - v[k].a][j - v[k].b] + v[k].c);
            }
        }
    }
    cout << dp[m][g] << endl;;
}
