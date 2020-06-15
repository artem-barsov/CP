#include <bits/stdc++.h>

using namespace std;

struct Coord {
    long long x = 0, y = 0;
};

Coord operator + (const Coord & lhs, const Coord & rhs) {
    return Coord{lhs.x + rhs.x, lhs.y + rhs.y};
}

Coord operator * (const long long k, const Coord & rhs) {
    return Coord{k * rhs.x, k * rhs.y};
}

Coord operator % (const Coord & lhs, const long long mod) {
    return Coord{lhs.x % mod, lhs.y % mod};
}

long long j = 0;

Coord delta(std::string move, const long long n) {
    Coord d;
    while (j != n) {
        if      (move[j] == 'E') d.x++;
        else if (move[j] == 'W') d.x--;
        else if (move[j] == 'S') d.y++;
        else if (move[j] == 'N') d.y--;
        else if (move[j] == ')') return d;
        else {
            long long k = move[j]-'0';
            j += 2;
            d = d + (k * delta(move, n)) % 1000000000;
        }
        j++;
    }
    return d;
}

void solve() {
    j = 0;
    std::string move;
    std::cin >> move;
    Coord pos = Coord{1, 1};
    Coord del = delta(move, move.length());

    del.x = del.x % 1000000000;
    del.y = del.y % 1000000000;

    pos = pos + del;

    if (pos.x < 1) pos.x += 1000000000ll;
    if (pos.y < 1) pos.y += 1000000000ll;
    if (pos.x > 1000000000ll) pos.x -= 1000000000ll;
    if (pos.y > 1000000000ll) pos.y -= 1000000000ll;
    std::cout << pos.x << ' ' << pos.y << '\n';
}

int main(int argc, char const *argv[]) {
    long long t;
    std::cin >> t;
    for (long long i = 1; i <= t; i++) {
        std::cout << "Case #" << i << ": ";
        solve();
    }
}
