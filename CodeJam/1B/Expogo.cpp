#include <bits/stdc++.h>

using namespace std;

struct Coord {
    int x = 0, y = 0;
};

int main(int argc, char const *argv[]) {
    char side;
    int len = 1;
    Coord cur;
    while (true) {
        std::cin >> side;
        if      (side == 'N') {
            cur.y += len;
            len <<= 1;
        }
        else if (side == 'S') {
            cur.y -= len;
            len <<= 1;
        }
        else if (side == 'E') {
            cur.x += len;
            len <<= 1;
        }
        else if (side == 'W') {
            cur.x -= len;
            len <<= 1;
        }
        std::cout << cur.x << ' ' << cur.y << '\n';
        
    }
}

// 2 3
// SEN
2 3

0000 0000
0000 1111
0010 1111
0010 0011

0010 0011
