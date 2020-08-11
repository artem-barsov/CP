#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main(int argc, char const *argv[]) {
    ull k;
    std::cin >> k;
    std::vector<int> cnt(10, 1);
    ull prod = 1;
    int pos = 0;
    while (k > prod) {
        prod = prod / cnt[pos] * (cnt[pos]+1);
        cnt[pos]++;
        pos = (pos+1) % cnt.size();
    }
    std::string letters = "codeforces";
    for (size_t i = 0; i < letters.size(); i++)
        std::cout << std::string(cnt[i], letters[i]);
    std::cout << '\n';
}
