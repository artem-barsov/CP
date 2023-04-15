#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

int main() {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    map<char, string> morse;
    morse['q'] = "--.-";
    morse['w'] = ".--";
    morse['e'] = ".";
    morse['r'] = ".-.";
    morse['t'] = "-";
    morse['y'] = "-.--";
    morse['u'] = "..-";
    morse['i'] = "..";
    morse['o'] = "---";
    morse['p'] = ".--.";
    morse['a'] = ".-";
    morse['s'] = "...";
    morse['d'] = "-..";
    morse['f'] = "..-.";
    morse['g'] = "--.";
    morse['h'] = "....";
    morse['j'] = ".---";
    morse['k'] = "-.-";
    morse['l'] = ".-..";
    morse['z'] = "--..";
    morse['x'] = "-..-";
    morse['c'] = "-.-.";
    morse['v'] = "...-";
    morse['b'] = "-...";
    morse['n'] = "-.";
    morse['m'] = "--";
    string s;
    cin >> s;
    string t;
    for (char c : s) t += morse[c];
    string r = t;
    reverse(r.begin(), r.end());
    cout << (t == r ? "yes" : "no") << '\n';
}