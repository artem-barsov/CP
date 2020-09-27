#include <bits/stdc++.h>

using namespace std;

int ones(long long n) {
    int c = 0;
    for (long long i = 0ll; i < 64ll; i++) {
        if (((1ll << i) & n) != 0) {
            c++;
        }
    }
    return c;
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::cout << ones(n) << '\n';
}
