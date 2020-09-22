#include <bits/stdc++.h>

using namespace std;

struct Coord {
    char v, h;
    Coord() { }
    Coord(std::string fig) : v(fig[0]), h(fig[1]) { }
    Coord(char v, char h) : v(v), h(h) { }
} wk, wt, bk;

bool operator == (const Coord & lhs, const Coord & rhs) {
    return (lhs.v == rhs.v) && (lhs.h == rhs.h);
}

bool cell_on_desk(Coord cell) {
    return (cell.v >= 'a') && (cell.v <= 'h') && (cell.h >= '1') && (cell.h <= '8');
}
bool cell_under_king(Coord cell, Coord king) {
    return ((abs(king.v-cell.v) <= 1) && (abs(king.h-cell.h) <= 1));
}
bool cell_under_turm(Coord cell) {
    return ((cell.v == wt.v) && !((wk.v == wt.v) && (((cell.h < wk.h) && (wk.h < wt.h)) || ((wt.h < wk.h) && (wk.h < cell.h)))))
        || ((cell.h == wt.h) && !((wk.h == wt.h) && (((cell.v < wk.v) && (wk.v < wt.v)) || ((wt.v < wk.v) && (wk.v < cell.v)))));
}
bool cell_accessible(Coord cell) {
    return ((cell == wt) && !cell_under_king(wt, wk))
        || (cell_on_desk(cell) && !cell_under_king(cell, wk) && !cell_under_turm(cell));
}
void debug() {
    for (char h = '8'; h >= '1'; h--) {
        printf("%c ", h);
        for (char v = 'a'; v <= 'h'; v++) {
            printf("%c ", (Coord(v,h)==wk ? 'W' : (Coord(v,h)==wt ? 'T' : (Coord(v,h)==bk ? 'B' : (cell_accessible(Coord(v, h)) ? '.' : '+')))));
        }
        printf("\n");
    }
    printf("  ");
    for (char v = 'a'; v <= 'h'; v++) {
        printf("%c ", v);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    std::string figure;
    std::cin >> figure;
    wk = Coord(figure);
    std::cin >> figure;
    wt = Coord(figure);
    std::cin >> figure;
    bk = Coord(figure);
    if (cell_under_king(bk, wk)) std::cout << "Strange" << '\n';
    else {
        if (cell_under_turm(bk)) {
            bool hasAccessible = false;
            for (char h = bk.h+1; h >= bk.h-1; h--) {
                for (char v = bk.v-1; v <= bk.v+1; v++) {
                    hasAccessible = hasAccessible || cell_accessible(Coord(v, h));
                }
            }
            if (hasAccessible) std::cout << "Check" << '\n';
            else std::cout << "Checkmate" << '\n';
        }
        else {
            bool hasAccessible = false;
            for (char h = bk.h+1; h >= bk.h-1; h--) {
                for (char v = bk.v-1; v <= bk.v+1; v++) {
                    if ((bk.v != v) || (bk.h != h)) {
                        hasAccessible = hasAccessible || cell_accessible(Coord(v, h));
                    }
                }
            }
            if (hasAccessible) std::cout << "Normal" << '\n';
            else std::cout << "Stalemate" << '\n';
        }
    }
}
