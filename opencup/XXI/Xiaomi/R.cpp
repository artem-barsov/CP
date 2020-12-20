#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    do {
        int p = 0;
        std::cin >> n;
        std::cin.ignore();
        for (int i = 0; i < n; i++) {
            std::string s;
            getline(cin, s);
            if (i == 0) {
                for (; s[p] == ' '; p++);
            }
            for (; (p < s.length()) && (s[p] != ' '); p++);
        }
        if (n) std::cout << p + 1 << '\n';
    } while(n);
    return 0;
}
