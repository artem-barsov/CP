#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

enum RES { WIN, LOS, DRW, UND };

char dfs(vector<vector<vector<char> > >& dp, const string& s, int l, int r, char c) {
    if (dp[l][r][c-'a'] != UND)
        return dp[l][r][c-'a'];
    char res1 = UND, res2 = UND;
    if ((r-l)&1) { // Alice goes
        res1 = dfs(dp, s, l+1, r, s[l]);
        res2 = dfs(dp, s, l, r-1, s[r]);
    }
    else { // Bob goes
        res1 = dfs(dp, s, l+1, r, 'a');
        res2 = dfs(dp, s, l, r-1, 'a');
        if (res1 == DRW) 
            res1 = (s[l] < c ? LOS : s[l] > c ? WIN : DRW);
        if (res2 == DRW) 
            res2 = (s[r] < c ? LOS : s[r] > c ? WIN : DRW);
    }
    if (res1 == LOS || res2 == LOS)
        return dp[l][r][c-'a'] = WIN;
    if (res1 == WIN && res2 == WIN)
        return dp[l][r][c-'a'] = LOS;
    return dp[l][r][c-'a'] = DRW;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<vector<char> > > dp(n, vector<vector<char> >(n, vector<char>('z'-'a'+1, UND)));
    for (int l = 0; l < n-1; l++)
        dp[l][l+1][0] = (s[l] != s[l+1] ? WIN : DRW);
    char res = dfs(dp, s, 0, n-1, 'a');
    if      (res == WIN) cout << "Alice" << '\n';
    else if (res == LOS) cout << "Bob" << '\n';
    else if (res == DRW) cout << "Draw" << '\n';
    else                 cout << "Error" << '\n';
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int t;
    cin >> t;
    while (t--) solve();
}