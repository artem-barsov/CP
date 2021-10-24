#include <bits/stdc++.h>

using namespace std;

struct pr { int n, c; };

bool fuck(map<int, int>& nums, vector<vector<pr>>& mp) {
    for (int i = 0; i < mp.size(); i++) {
        bool fl = true;
        for (int j = 0; j < mp[i].size(); j++) {
            if (nums[mp[i][j].n] < mp[i][j].c) fl = false;
        }
        if (!fl) continue;
        for (int j = 0; j < mp[i].size(); j++) {
            nums[mp[i][j].n] -= mp[i][j].c;
        }
        return true;
    }
    return false;
}

void solve() {
    vector<vector<pr>> mp{
        {{9, 1}, {1, 1}},

        {{8, 1}, {2, 1}},
        {{8, 1}, {1, 2}},

        {{7, 1}, {3, 1}},
        {{7, 1}, {2, 1}, {1, 1}},
        {{7, 1}, {1, 3}},

        {{6, 1}, {4, 1}},
        {{6, 1}, {2, 2}},
        {{6, 1}, {3, 1}, {1, 1}},
        {{6, 1}, {2, 1}, {1, 2}},
        {{6, 1}, {1, 4}},

        {{5, 2}},
        {{5, 1}, {4, 1}, {1, 1}},
        {{5, 1}, {3, 1}, {2, 1}},
        {{5, 1}, {3, 1}, {1, 2}},
        {{5, 1}, {2, 2}, {1, 1}},
        {{5, 1}, {2, 1}, {1, 3}},
        {{5, 1}, {1, 5}},

        {{4, 2}, {2, 1}},
        {{4, 2}, {1, 2}},
        {{4, 1}, {3, 2}},
        {{4, 1}, {3, 1}, {2, 1}, {1, 1}},
        {{4, 1}, {3, 1}, {1, 3}},
        {{4, 1}, {2, 3}},
        {{4, 1}, {2, 2}, {1, 2}},
        {{4, 1}, {2, 1}, {1, 4}},
        {{4, 1}, {1, 6}},

        {{3, 3}, {1, 1}},
        {{3, 2}, {2, 2}},
        {{3, 2}, {2, 1}, {1, 2}},
        {{3, 2}, {1, 4}},
        {{3, 1}, {2, 3}, {1, 1}},
        {{3, 1}, {2, 2}, {1, 3}},
        {{3, 1}, {2, 1}, {1, 5}},
        {{3, 1}, {1, 7}},

        {{2, 5}},
        {{2, 4}, {1, 2}},
        {{2, 3}, {1, 4}},
        {{2, 2}, {1, 6}},
        {{2, 1}, {1, 8}},

        {{1, 10}}
    };

    int n;
    cin >> n;
    map<int, int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums[x]++;
    }
    int ans = 0;
    while (fuck(nums, mp)) ans++;
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
