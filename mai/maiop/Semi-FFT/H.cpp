#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    std::string op = "+";
    if (a[0] == '-') {
        a = a.substr(1);
        if (b[0] == '-') b = b.substr(1);
        else op = "-";
    }
    else if (b[0] == '-') {
        b = b.substr(1);
        op = "-";
    }
    std::vector<std::string> spec_a;
    std::string zeros = "";
    for (int i = a.length()-1; i >= 0; i--) {
        if (a[i] != '0') spec_a.push_back(a[i] + zeros);
        zeros += '0';
    }
    std::vector<std::string> spec_b;
    zeros = "";
    for (int i = b.length()-1; i >= 0; i--) {
        if (b[i] != '0') spec_b.push_back(b[i] + zeros);
        zeros += '0';
    }
    if (op == "-") std::cout << '-';
    for (int i = spec_a.size()-1; i >= 0; i--) {
        for (int j = spec_b.size()-1; j >= 0; j--) {
            std::cout << spec_a[i]+" x "+spec_b[j];
            if (i || j) std::cout << ' '+op+' ';
        }
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) solve();
}
