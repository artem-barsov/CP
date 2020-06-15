#include <bits/stdc++.h>

using namespace std;

struct Tdata {
    string integer, real;
};

bool operator < (const Tdata & lhs, const Tdata & rhs) {
    if (lhs.integer.length() != rhs.integer.length())
        return lhs.integer.length() < rhs.integer.length();
    if (lhs.integer != rhs.integer)
        return lhs.integer < rhs.integer;
    return lhs.real < rhs.real;
}

int main() {
    int n, k;
    cin >> n >> k;
    getchar();
    set<Tdata> data;
    for (int i = 0; i < n; i++) {
        Tdata tmp = {"",""};
        char ch;
        while ((ch=getchar()) != '.') tmp.integer += ch;
        while ((ch=getchar()) != '\n') tmp.real += ch;
        data.insert(tmp);
    }
    auto it = data.end();
    for (int i = 0; i < k; i++) --it;
    cout << it->integer << '.' << it->real;
}
