#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct TStud {
    int got = 0;
    set<int> in;
};

void join(int x, int y, std::vector<int>& groups, std::vector<TStud>& students) {
    students[x].in.insert(y);
    students[x].got -= groups[y];
}

void quit(int x, int y, std::vector<int>& groups, std::vector<TStud>& students) {
    students[x].in.erase(y);
    students[x].got += groups[y];
}

void send(int x, int y, std::vector<int>& groups, std::vector<TStud>& students) {
    ++groups[y];
    --students[x].got;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<TStud> students(m);
    std::vector<int> groups(n);
    int t, x, y;
    int event;
    for (event = 0; event < s; event++) {
        std::cin >> t >> x >> y;
        --x; --y;
        switch (t) {
        case 1:  // log(n)
            join(x, y, groups, students);
            break;
        case 2:  // log(n)
            quit(x, y, groups, students);
            break;
        case 3:  // 1
            send(x, y, groups, students);
            break;
        }
    }
    int a = 0;
    int i;
    for (i = 0; i < m; i++) {
        a = 0;
        for (set<int>::iterator j = students[i].in.begin(); j != students[i].in.end(); ++j) {
            a += groups[*j];
        }
        std::cout << students[i].got + a << '\n';
    }
}
