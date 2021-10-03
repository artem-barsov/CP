#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    std::string s;
    std::cin >> s;
    std::string t1, t2;
    for (int i = 0; i < s.length();) {
        t1 += '0' + !(s[i] == 'z');
        i += 3 + (s[i] == 'z');
    }
    std::cin >> s;
    for (int i = 0; i < s.length();) {
        t2 += '0' + !(s[i] == 'z');
        i += 3 + (s[i] == 'z');
    }
    if (t1.length() != t2.length())
        std::cout << (t1.length() < t2.length() ? '<' : '>') << '\n';
    else {
        for (int i = 0; i < t1.length(); i++) {
            if (t1[i] != t2[i]) {
                std::cout << (t1[i] < t2[i] ? '<' : '>') << '\n';
                return 0;
            }
        }
        std::cout << '=' << '\n';
    }
}
