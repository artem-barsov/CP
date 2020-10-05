#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    long long x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int a = x1*(y2-y1) - (x2-x1)*y1;
    int b = x2*(y3-y2) - (x3-x2)*y2;
    int c = x3*(y1-y3) - (x1-x3)*y3;
    if ((a>=0)&&(b>=0)&&(c>=0) || (a<=0)&&(b<=0)&&(c<=0))
        std::cout << 987654321 << '\n';
    else
        printf("%d %d %d %d %d %d\n", -x1, -y1, -x2, -y2, -x3, -y3);
}
