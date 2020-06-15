#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unsigned long long n;
    std::cin >> n;
    std::multiset<unsigned long long> clan;
    for (int i = 0; i < n; i++) {
        unsigned long long inp;
        std::cin >> inp;
        clan.insert(inp);
    }
    while (clan.size() > 1) {
        unsigned long long a = *clan.begin();
        clan.erase(clan.begin());
        std::cout << a << ' ';
        unsigned long long b = *clan.begin();
        clan.erase(clan.begin());
        std::cout << b << '\n';
        clan.insert(a+b);
    }
}
