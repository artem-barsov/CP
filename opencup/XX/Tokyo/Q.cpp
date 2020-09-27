#include <bits/stdc++.h>

using namespace std;

bool comp (const pair<std::string, int> & lhs, const pair<std::string, int> & rhs) {
    if (lhs.second != rhs.second) return lhs.second > rhs.second;
    return lhs.first < rhs.first;
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    map<std::string, int> votes;
    for (int i = 0; i < n; i++) {
        std::string name;
        std::cin >> name;
        votes[name]++;
    }
    std::vector<pair<std::string, int> > cands(votes.begin(), votes.end());
    sort(cands.begin(), cands.end(), comp);
    for (size_t i = 0; (i < cands.size()) && (cands[i].second == cands[0].second); i++) {
        std::cout << cands[i].first << '\n';
    }
}
