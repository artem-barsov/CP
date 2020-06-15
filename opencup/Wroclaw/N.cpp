#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    std::vector<int> dice(6);
    for (int i = 0; i < 6; i++) std::cin >> dice[i];
    int vars = 1;
    while ((vars++) % 1000000) {
        int offset = 1;
        for (int i = 0; i < 6; i++) {
            vars += (vars / offset % 10 / 3) * offset * 10;
            if (vars / offset % 10 > 2) vars -= 3 * offset;
            offset *= 10;
        }
        int q[3] = {0, 0, 0};
        offset = 1;
        for (int i = 0; i < 6; i++) {
            q[vars / offset % 10]++;
            offset *= 10;
        }
        if ((q[0]==2)&&(q[1]==2)&&(q[2]==2)) {
            int w[3] = {0,0,0};
            offset = 1;
            for (int i = 0; i < 6; i++) {
                w[vars / offset % 10] += dice[i];
                offset *= 10;
            }
            if ((w[0]==w[1]) && (w[1]==w[2])) {
                std::cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    std::cout << "No" << '\n';
}
