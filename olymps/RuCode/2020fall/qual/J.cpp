#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    std::string s;
    std::cin >> s;
    s += ',';
    std::map<std::string, int> item;
    int l = 0, time;
    std::string ammun;
    for (int r = 0; r < s.length(); r++) {
        if (s[r] == ':') {
            ammun = s.substr(l, r-l);
            l = r+1;
        }
        else if (s[r] == ',') {
            item[ammun] = atoi(s.substr(l, r-l).c_str());
            l = r+1;
        }
    }
    std::cin >> s;
    s += '|';
    l = 0;
    int m = INT_MAX-1, cur = 0;
    for (int r = 0; r < s.length(); r++) {
        if (s[r] == '&') {
            cur = max(cur, item[s.substr(l, r-l)]);
            l = r+1;
        }
        else if (s[r] == '|') {
            cur = max(cur, item[s.substr(l, r-l)]);
            l = r+1;
            m = min(m, cur);
            cur = 0;
        }
    }
    std::cout << m << '\n';
}
