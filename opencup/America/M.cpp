#include <bits/stdc++.h>

using namespace std;

bool comp (std::pair<char, int> lhs, std::pair<char, int> rhs) {
    return lhs.second > rhs.second;
}

int main(int argc, char const *argv[]) {
    std::map<char, int> msyms;
    std::string s;
    getline(std::cin, s);
    int len = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            msyms[toupper(s[i])]++;
            len++;
        }
    }
    std::vector<std::pair<char, int> > vsyms;
    // for (auto v : msyms) { vsyms.push_back(v); }
    for (std::map<char, int>::iterator it = msyms.begin(); it != msyms.end(); it++) {
        vsyms.push_back(*it);
    }
    sort(vsyms.begin(), vsyms.end(), comp);
    int enc_gruppe = 1, prev_enc_gruppe = 1, enc_sum = 1, cur_enc_len = 1, out = 0;
    for (int i = 0; i < vsyms.size(); i++) {
        out += vsyms[i].second * cur_enc_len;
        if (i == enc_sum-1) {
            prev_enc_gruppe = enc_gruppe + prev_enc_gruppe;
            swap(enc_gruppe, prev_enc_gruppe);
            enc_sum += enc_gruppe;
            cur_enc_len += 2;
        }
    }
    std::cout << out + 3*(len-1) << '\n';
}
