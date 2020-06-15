#include <bits/stdc++.h>

using namespace std;

struct TBook {
    int id, score;
};

bool operator < (TBook &lhs, TBook &rhs) {
    return lhs.score >= rhs.score;
}

struct TLibrary {
    int id;
    int nSignupDays;
    int nBooksPerDay;
    std::vector<TBook> vBooksContent;
};

bool operator < (TLibrary &lhs, TLibrary &rhs) {
    return lhs.nSignupDays < rhs.nSignupDays;
}

int main(int argc, char const *argv[]) {
    int nBooks, nLibraries, nDays;
    std::cin >> nBooks >> nLibraries >> nDays;
    std::vector<int> nScore(nBooks);
    for (size_t i = 0; i < nBooks; i++) std::cin >> nScore[i];
    std::vector<TLibrary> Libraries;
    for (size_t i = 0; i < nLibraries; i++) {
        int this_id = i, this_nSignupDays, this_nBooksPerDay, n;
        std::cin >> n;
        std::cin >> this_nSignupDays;
        std::cin >> this_nBooksPerDay;
        std::vector<TBook> this_vBooksContent;
        for (size_t i = 0; i < n; i++) {
            int id;
            std::cin >> id;
            this_vBooksContent.push_back(TBook{id, nScore[id]});
        }
        Libraries.push_back(TLibrary{this_id, this_nSignupDays, this_nBooksPerDay, this_vBooksContent});
    }
    sort(Libraries.begin(), Libraries.end());
    std::cout << nLibraries << '\n';
    for (size_t i = 0; i < nLibraries; i++) {
        std::cout << Libraries[i].id << ' ' << Libraries[i].vBooksContent.size() << '\n';
        sort(Libraries[i].vBooksContent.begin(), Libraries[i].vBooksContent.end());
        for (size_t j = 0; j < Libraries[i].vBooksContent.size(); j++) {
            std::cout << Libraries[i].vBooksContent[j].id << ' ';
        }
        std::cout << '\n';
    }
}
