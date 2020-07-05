#include <bits/stdc++.h>

using namespace std;

map<int, int> digit_m;

std::string minMatch(int n) {
    std::string res;
    res += std::string(n / digit_m[8], '8');
    n %= digit_m[8];
    res += std::string(n / digit_m[0], '0');
    n %= digit_m[0];
    res += std::string(n / digit_m[2], '2');
    n %= digit_m[2];
    res += std::string(n / digit_m[4], '4');
    n %= digit_m[4];
    res += std::string(n / digit_m[7], '7');
    n %= digit_m[7];
    res += std::string(n / digit_m[1], '1');
    n %= digit_m[1];
    sort(res.begin(), res.end());
    if (res[0] == '0') {
        int i = 0;
        while (res[i] == '0') {
            i++;
        }
        swap(res[0], res[i]);
    }
    return res;
}

std::string maxMatch(int n) {
    std::string res;
    if (n%2==0) {
        res += std::string(n / digit_m[1], '1');
    }
    else {
        res += std::string(n / digit_m[1] - 1, '1');
        res += '7';
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    digit_m[8] = 7;
    digit_m[0] = 6;
    digit_m[6] = 6;
    digit_m[9] = 6;
    digit_m[2] = 5;
    digit_m[3] = 5;
    digit_m[5] = 5;
    digit_m[4] = 4;
    digit_m[7] = 3;
    digit_m[1] = 2;
    int n;
    std::cin >> n;
    std::cout << minMatch(n) << ' ' << maxMatch(n) << '\n';
}
