#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct TTeam {
    std::vector<std::string> players;
    bool court[10];
    int score[10];
};

struct TOut {
    std::string player, team;
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    std::string name1, name2;
    map<std::string, TTeam> team;
    queue<TOut> out;
    std::cin >> name1;
    team[name1].players.resize(5);
    for (int i = 0; i < 5; i++) {
        std::cin >> team[name1].players[i];
        out.push(TOut{team[name1].players[i], name1});
    }
    fill(team[name1].court, team[name1].court+5, true);
    fill(team[name1].court+5, team[name1].court+10, false);
    fill(team[name1].score, team[name1].score+10, 0);

    std::cin >> name2;
    team[name2].players.resize(5);
    for (int i = 0; i < 5; i++) {
        std::cin >> team[name2].players[i];
        out.push(TOut{team[name2].players[i], name2});
    }
    fill(team[name2].court, team[name2].court+5, true);
    fill(team[name2].court+5, team[name2].court+10, false);
    fill(team[name2].score, team[name2].score+10, 0);

    int q;
    std::cin >> q;
    for (int t = 0; t < q; t++) {
        std::string x, act;
        std::cin >> x >> x >> act;
        if (act[0] == 's') { // scored
            std::string lose = (x == name1 ? name2 : name1);
            int n;
            std::cin >> n;
            for (int i = 0; i < 10; i++) {
                if (team[x].court[i])
                    team[x].score[i] += n;
                if (team[lose].court[i])
                    team[lose].score[i] -= n;
            }
        }
        else { // replaced
            std::string y, z;
            std::cin >> y >> z >> z;
            bool found = false;
            for (int i = 0; i < team[x].players.size(); i++) {
                if (team[x].players[i] == y) {
                    team[x].court[i] = false;
                }
                else if (team[x].players[i] == z) {
                    team[x].court[i] = true;
                    found = true;
                }
            }
            if (!found) {
                team[x].players.push_back(z);
                team[x].court[team[x].players.size()-1] = true;
                out.push(TOut{z, x});
            }
        }
    }

    while (!out.empty()) {
        std::cout << out.front().player << " (" << out.front().team << ") ";
        for (int i = 0; i < team[out.front().team].players.size(); i++) {
            if (team[out.front().team].players[i] == out.front().player) {
                if (team[out.front().team].score[i] > 0) {
                    std::cout << '+';
                }
                std::cout << team[out.front().team].score[i] << '\n';
                break;
            }
        }
        out.pop();
    }
}
