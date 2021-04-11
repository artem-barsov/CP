#define _CRT_DISABLE_PERFCRIT_LOCKS
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    int pos1;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] == 1) pos1 = i;
    }
    vector<int> ans;
    for (int i = 0; i <= pos1; i++) {
        for (size_t j = pos1; j < n; j++) {
            vector<int> tmpv(j-i+1);
            copy(&x[i], &x[j+1], tmpv.begin());
            sort(tmpv.begin(), tmpv.end());
            bool isPerest = true;
            for (size_t k = 1; k < tmpv.size(); k++)
                if (tmpv[k] - tmpv[k-1] != 1) isPerest = false;
            if (isPerest) ans.push_back(tmpv.back());
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << "1 " << ans[i] << '\n';
}
