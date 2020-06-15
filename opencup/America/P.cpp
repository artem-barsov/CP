#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    std::string alph, s;
    std::cin >> alph >> s;
    std::set<std::string> lev_list;
    for (int i = 0; i <= s.length(); i++) {
        for (int j = 0; j < alph.length(); j++) {
            lev_list.insert(s.substr(0, i) + alph[j] + s.substr(i, s.length()));
            if (i < s.length()) {
                lev_list.insert(s.substr(0, i) + alph[j] + s.substr(i+1, s.length()));
            }
        }
        if (i < s.length()) {
            lev_list.insert(s.substr(0, i) + s.substr(i+1, s.length()));
        }
    }
    lev_list.erase(s);
    // for (auto & v : lev_list) {
    //     std::cout << v << '\n';
    // }
    for (std::set<std::string>::iterator it = lev_list.begin(); it != lev_list.end(); it++)
        std::cout << *it << '\n';
}
