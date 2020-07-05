#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::map<std::string, int> verdicts;
    for (size_t i = 0; i < n; i++) {
        std::string inp;
        std::cin >> inp;
        verdicts[inp]++;
    }
    printf("AC x %d\n", verdicts["AC"]);
    printf("WA x %d\n", verdicts["WA"]);
    printf("TLE x %d\n", verdicts["TLE"]);
    printf("RE x %d\n", verdicts["RE"]);
}
