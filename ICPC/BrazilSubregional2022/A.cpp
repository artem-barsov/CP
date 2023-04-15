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
    int n, c;
    cin >> n >> c;
    map<string, int> word_cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int idx = s.find('*');
        for (int c = 'a'; c <= 'z'; c++) {
            s[idx] = c;
            word_cnt[s]++;
        }
    }
    string ans;
    int maxoc = 0;
    for (auto &&[word, cnt] : word_cnt) {
        if (cnt > maxoc) {
            ans = word;
            maxoc = cnt;
        }
    }
    cout << ans << ' ' << maxoc << '\n';
}