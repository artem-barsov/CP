#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::string s;
    std::cin >> n >> s;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>' && l == -1) l = n - i;
        if (s[i] == '<') r = i + 1;
    }
    std::cout << max(l, r) << '\n';
}
