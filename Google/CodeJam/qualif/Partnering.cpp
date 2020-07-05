#include <bits/stdc++.h>

using namespace std;

struct Task {
    int start = 0, end = 0;
    char * partner;
};

std::string solve() {
    int n;
    std::cin >> n;
    std::string schedule(n, 0);
    std::vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tasks[i].start >> tasks[i].end;
        tasks[i].partner = &schedule[i];
    }

    sort(tasks.begin(), tasks.end(),
        [](const Task & lhs, const Task & rhs){ return lhs.start < rhs.start; });

    Task Cameron, Jamie;
    for (int i = 0; i < tasks.size(); i++) {
        if (Cameron.end <= tasks[i].start) {
            Cameron = tasks[i];
            *tasks[i].partner = 'C';
        }
        else if (Jamie.end <= tasks[i].start) {
            Jamie = tasks[i];
            *tasks[i].partner = 'J';
        }
        else return "IMPOSSIBLE";
    }
    return schedule.c_str();
}

int main(int argc, char const *argv[]) {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++) printf("Case #%d: %s\n", i, solve().c_str());
}
