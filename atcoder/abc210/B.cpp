#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::cout << ((s.find_first_of("1")&1) ? "Aoki" : "Takahashi") << '\n';
}
