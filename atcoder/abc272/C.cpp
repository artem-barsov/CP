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
    int n;
    cin >> n;
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a&1) odd.push_back(a);
        else even.push_back(a);
    }
    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());
    int ans = 0;
    if (even.size() < 2 && odd.size() < 2)
        ans = -1;
    else {
        if (even.size() >= 2)
            ans = even[0] + even[1];
        if (odd.size() >= 2)
            ans = max(ans, odd[0] + odd[1]);
    }
    cout << ans << '\n';
}