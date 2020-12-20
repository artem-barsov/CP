#include <iostream>
#include <vector>
#include <cmath>

int main() {
    long long d, s1, s2;
    std::cin >> d >> s1 >> s2;
    while (d != 0 || s1 != 0 || s2 != 0) {
        if (s2 > s1) {
            std::swap(s1, s2);
        }
        long long ss = std::round((3600.0 * d * (s1 - s2)) / (double)(s2 * s1));
        long long s = ss % 60;
        long long h = ss / 3600;
        long long m = (ss % 3600) / 60;
        std::cout << h << ":";
        if (m < 10)
            std::cout << '0' << m;
        else
            std::cout << m;
        std::cout << ":";
        if (s < 10)
            std::cout << '0' << s;
        else
            std::cout << s;
        std::cout << std::endl;
        std::cin >> d >> s1 >> s2;
    }
}
