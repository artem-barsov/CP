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
    stringstream ss;
    ss << hex << n;
    string s;
    ss >> s;
    if (s.length() == 1) s = '0' + s;
    for (auto &&ch : s)
    {
        if ('a' <= ch && ch <= 'z')
            ch = toupper(ch);
    }
    cout << s << '\n';
}