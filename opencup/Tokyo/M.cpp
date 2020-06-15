#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int k;
    std::cin >> k;
    std::string s = "a";
    int value = 0;
    bool a = true;
    while (value < k) {
        if (a) {
            s += char(min(int('z'), k-value+'a'));
        }
        else {
            s += 'z' - char(min(int('z'), k-value+'a')) + 'a';
        }
        value += abs(s[s.length()-1] - s[s.length()-2]);
        a ^= 1;
    }
    if (s.length() > 2) {
        if (a) {
            int delta = (s[s.length()-1] - 'a') / 2;
            s[1] -= delta;
            s[s.length()-1] -= 2*delta;
        }
        else {
            int delta = ('z' - s[s.length()-1]) / 2;
            s[1] -= delta;
            s[s.length()-1] += 2*delta;
        }
    }
    std::cout << s << '\n';
}
// std::cout << abs('a'-'o')+abs('a'-'o')+abs('a'-'z')+abs('b'-'z') << '\n';
// std::cout << abs('a'-'z')+abs('a'-'z')+abs('a'-'z')+abs('x'-'z') << '\n';
