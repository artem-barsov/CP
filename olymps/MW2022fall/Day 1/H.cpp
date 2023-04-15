#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

const int MAXN = 16;

bool isPalindrom(const string& s) {
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i] != s[s.length()-i-1])
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    string s;
    cin >> s;
    const int n = s.length();
    vector<char> isPal(1 << n, false);
    for (size_t bf = 0; bf < (1ull << n); bf++) {
        bitset<MAXN> bs(bf);
        string t;
        for (int i = 0; i < n; i++) {
            if (bs[i]) t += s[i];
        }
        isPal[bf] = isPalindrom(t);
        cout << bs << ' ' << t << ' ' << (isPal[bf]?"\tYES":"") << '\n';
    }

}