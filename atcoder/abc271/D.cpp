#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<vector<int>> memo(n+1, vector<int>(s+500, 0));
    memo[0][0] = 123;
    for (int i = 0; i < n; i++) {
        for (int sum = 0; sum <= s; sum++) {
            if (memo[i][sum]) {
                memo[i+1][sum+a[i]] = 1;
                memo[i+1][sum+b[i]] = 2;
            }
        }
    }
    if (!memo[n][s]) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes\n";
    stack<char> ans;
    int nn = n, summ = s;
    while (nn > 0) {
        if (memo[nn][summ] == 1) {
            ans.push('H');
            summ -= a[nn-1];
        }
        else {
            ans.push('T');
            summ -= b[nn-1];
        }
        nn--;
    }
    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    cout << '\n';
}