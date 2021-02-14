#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int k1, k2;
    std::cin >> k1 >> k2;
    map<std::string, int> pieces;
    map<std::string, int> accord;
    accord["king"] = 1;
    accord["queen"] = 1;
    accord["bishop"] = 2;
    accord["knight"] = 2;
    accord["rook"] = 2;
    accord["pawn"] = 8;
    for (int i = 0; i < k1; i++) {
        std::string color, rank;
        std::cin >> color >> rank;
        ++pieces[color+' '+rank];
    }
    queue<std::string> qout;
    for (int i = 0; i < k2; i++) {
        std::string color, rank;
        std::cin >> color >> rank;
        std::string fullname = color+' '+rank;
        if (pieces[fullname] < accord[rank]) {
            qout.push(fullname);
            ++pieces[fullname];
        }
    }
    for (auto& it : accord) {
        if ((pieces["white "+it.first] < it.second) ||
            (pieces["black "+it.first] < it.second)) {
            std::cout << "impossible" << '\n';
            return 0;
        }
    }
    while (!qout.empty()) {
        std::cout << qout.front() << '\n';
        qout.pop();
    }
}
