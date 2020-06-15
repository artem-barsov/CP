#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    std::string ideal = "BSUIROPENX";
    int n;
    std::cin >> n;
    std::vector<int> vsufs;
    std::vector<long long> anz(10);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if (s.length() < 10) {
            bool isPref = true;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] != ideal[j]) {
                    isPref = false;
                    break;
                }
            }
            if (isPref) anz[s.length()]++;

            bool isSuf = true;
            for (int j = 0; j < s.size(); j++) {
                if (s[s.length()-1-j] != ideal[ideal.length()-1-j]) {
                    isSuf = false;
                    break;
                }
            }
            if (isSuf) vsufs.push_back(10 - s.length());
        }
    }
    int res = 0;
    for (int i = 0; i < vsufs.size(); i++) {
        res += anz[vsufs[i]];
    }
    std::cout << res << '\n';
}
