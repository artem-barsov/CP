#include <bits/stdc++.h>

using namespace std;

struct TEl {
    int idx, val;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<TEl> evens;
    std::vector<TEl> odds;
    for (int i = 0; i < 2*n; i++) {
        int a;
        std::cin >> a;
        if (a&1) odds.push_back(TEl{i+1, a});
        else evens.push_back(TEl{i+1, a});
    }
    if (odds.size()) {
        for (int i = 0; i < evens.size()/2; i++)
            std::cout << evens[2*i].idx << ' ' << evens[2*i+1].idx << '\n';
        for (int i = 0; i < (odds.size()-1)/2; i++)
            std::cout << odds[2*i].idx << ' ' << odds[2*i+1].idx << '\n';
    }
    else {
        for (int i = 0; i < (evens.size()-1)/2; i++)
            std::cout << evens[2*i].idx << ' ' << evens[2*i+1].idx << '\n';
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
