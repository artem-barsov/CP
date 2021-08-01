#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    char q,w,e,r;
    std::cin >> q >> w >> e >> r;
    q -= '0'; w -= '0'; e -= '0'; r -= '0';
    if (q==w && w==e && e ==r)
        std::cout << "Weak" << '\n';
    else if ((q+1)%10==w && (w+1)%10==e && (e+1)%10==r)
        std::cout << "Weak" << '\n';
    else
        std::cout << "Strong" << '\n';
}
