#include <bits/stdc++.h>

using namespace std;

void f(std::vector<int>& a, std::vector<int>& a1,
std::vector<int>& a2, int i, std::vector<bool>& swaped, int& c);

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n+1), a1(n+1), a2(n+1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a1[i];
        p[a1[i]]++;
        if (p[a1[i]] > 2) {
            std::cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> a2[i];
        p[a2[i]]++;
        if (p[a2[i]] > 2) {
            std::cout << -1 << '\n';
            return;
        }
    }
    std::vector<int> a(n+1);
    int c = 0;
    std::vector<bool> swaped(n+1);
    for (int i = 1; i <= n; i++) {
        if (!a[a2[i]]) {
            a[a2[i]] = i;
        }
        else {
            swap(a1[i], a2[i]);
            swaped[i] = !swaped[i];
            if (swaped[i]) c++;
            else c--;
            // printf("i=%d c=%d\n", i, c);
            f(a, a1, a2, i, swaped, c);
        }
    }
    // std::cout << '\n';
    // for (int i = 1; i <= n; i++) std::cout << a1[i] << ' ';
    // std::cout << '\n';
    // for (int i = 1; i <= n; i++) std::cout << a2[i] << ' ';
    // std::cout << '\n';
    if (c <= n/2) {
        std::cout << c << '\n';
        for (size_t i = 1; i <= n; i++) {
            if (swaped[i]) std::cout << i << ' ';
        }
    }
    else {
        std::cout << n-c << '\n';
        for (size_t i = 1; i <= n; i++) {
            if (!swaped[i]) std::cout << i << ' ';
        }
    }
    // std::cout << '\n' << '\n';
    std::cout << '\n';
}

void f(std::vector<int>& a, std::vector<int>& a1,
std::vector<int>& a2, int i, std::vector<bool>& swaped, int& c) {
    // printf("f i=%d\n", i);
    if (!a[a2[i]]) {
        a[a2[i]] = i;
    }
    else {
        swap(a1[a[a2[i]]], a2[a[a2[i]]]);
        swaped[a[a2[i]]] = !swaped[a[a2[i]]];
        if (swaped[a[a2[i]]]) c++;
        else c--;
        // printf("i=%d c=%d\n", a[a2[i]], c);
        a[a1[i]] = i;
        // f(a, a1, a2, a[a2[a[a2[i]]]], swaped, c);
        f(a, a1, a2, a[a2[i]], swaped, c);
    }
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    while (t--) solve();
}
