#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

struct Coord {
    int x, y;
};

bool operator == (const Coord & lhs, const Coord & rhs) {
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

bool available(Coord cell, std::vector<std::vector<ull> > desk) {
    return (cell.x >= 0) && (cell.x < desk[0].size())
        && (cell.y >= 0) && (cell.y < desk.size())
        && ((desk[cell.y][cell.x] == '.') || (desk[cell.y][cell.x] == 'X'));
}

int main(int argc, char const *argv[]) {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<ull> > desk(h, std::vector<ull>(w));
    queue<Coord> moves;
    Coord X;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char cell;
            std::cin >> cell;
            desk[i][j] = cell;
            if (desk[i][j] == 'K') {
                moves.push(Coord{j, i});
                desk[i][j] = 0;
            }
            if (desk[i][j] == 'X') X = Coord{j, i};
        }
    }
    while (!moves.empty()) {
        Coord cell = moves.front();
        moves.pop();
        if (cell == X) {
            std::cout << (ull)(desk[cell.y][cell.x]) << '\n';
            return 0;
        }

        if (available(Coord{cell.x+2, cell.y+1}, desk)) {
            desk[cell.y+1][cell.x+2] = desk[cell.y][cell.x]+1;
            moves.push(Coord{cell.x+2, cell.y+1});
        }
        if (available(Coord{cell.x+2, cell.y-1}, desk)) {
            desk[cell.y-1][cell.x+2] = desk[cell.y][cell.x]+1;
            moves.push(Coord{cell.x+2, cell.y-1});
        }
        if (available(Coord{cell.x-2, cell.y+1}, desk)) {
            desk[cell.y+1][cell.x-2] = desk[cell.y][cell.x]+1;
            moves.push(Coord{cell.x-2, cell.y+1});
        }
        if (available(Coord{cell.x-2, cell.y-1}, desk)) {
            desk[cell.y-1][cell.x-2] = desk[cell.y][cell.x]+1;
            moves.push(Coord{cell.x-2, cell.y-1});
        }
        if (available(Coord{cell.x+1, cell.y+2}, desk)) {
            desk[cell.y+2][cell.x+1] = desk[cell.y][cell.x]+1;
            moves.push(Coord{cell.x+1, cell.y+2});
        }
        if (available(Coord{cell.x+1, cell.y-2}, desk)) {
            desk[cell.y-2][cell.x+1] = desk[cell.y][cell.x]+1;
            moves.push(Coord{cell.x+1, cell.y-2});
        }
        if (available(Coord{cell.x-1, cell.y+2}, desk)) {
            desk[cell.y+2][cell.x-1] = desk[cell.y][cell.x]+1;
            moves.push(Coord{cell.x-1, cell.y+2});
        }
        if (available(Coord{cell.x-1, cell.y-2}, desk)) {
            desk[cell.y-2][cell.x-1] = desk[cell.y][cell.x]+1;
            moves.push(Coord{cell.x-1, cell.y-2});
        }
    }
    std::cout << -1 << '\n';

}
