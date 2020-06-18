#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

void out(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++)
        std::cout << bitset<20>(a[i]) << '\n';
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int pos = 0;
    bool flag;
    do {
        int c = 0;
        flag = false;
        for (int i = 0; i < n; i++) {
            c += (a[i] & (1 << pos))>0;
            flag = flag || (a[i] > (1 << pos));
        }
        for (int i = 0; i < c; i++)
            b[i] |= (1 << pos);
        pos++;
    } while(flag);
    // out(a);
    // std::cout << '\n';
    // out(b);
    ull sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += (ull)b[i]*b[i];
    std::cout << sum << '\n';
}
