#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int q;
    std::cin >> q;
    priority_queue<long long, std::vector<long long>, std::greater<long long>> balls;
    unsigned long long charge = 0;
    while (q--) {
        long long p, x;
        std::cin >> p;
        if (p == 1) {
            std::cin >> x;
            balls.push(x - charge);
        } else if (p == 2) {
            std::cin >> x;
            charge += x;
        } else {
            std::cout<<'\t'<< balls.top() + charge << '\n';
            balls.pop();
        }
    }
}
