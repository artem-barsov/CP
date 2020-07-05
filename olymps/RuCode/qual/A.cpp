#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    std::string s;
    getline(std::cin, s);
    int space = 2;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') space++;
        else if (space < 2) {
            std::cout << "unsafe" << '\n';
            return 0;
        }
        else space = 0;
    }
    std::cout << "safe" << '\n';
}
