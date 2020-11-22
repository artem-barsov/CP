#include <iostream>
#include <map>
#include <string>

int main() {
    int i = 0;
    int j = 32;
    int c = 0;
    int s;
    std::cin >> s;
    while (i < j) {
        c = i * i + j * j;
        if (c == s) break;
        if (c > s) --j;
        else ++i;
    }
    c = i * i + j * j;
    if (c == s) {
        std::cout << 0 << " " << i << "\n";
        std::cout << j << " " << 0 << "\n";
        std::cout << i + j << " " << j << "\n";
        std::cout << i << " " << j + i << "\n";
    }
    else
        std::cout << "Impossible\n";
}
