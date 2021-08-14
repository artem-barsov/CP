#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int s, t;
    std::cin >> s >> t;
    int ans = 0;
    for (int a = 0; a <= s; a++)
        for (int b = 0; b <= s-a; b++)
            for (int c = 0; c <= s-a-b; c++)
                ans += (a*b*c <= t);
    std::cout << ans << '\n';
}
