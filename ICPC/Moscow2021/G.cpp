#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

struct pr
{
    string name;
    string bt;
    string place;
};

void solve() {
    map<string, string> mp;
    mp["00"] = "13-16";
    mp["010"] = "9-12";
    mp["0110"] = "7-8";
    mp["01110"] = "5-6";
    mp["011110"] = "4";
    mp["0111110"] = "3";
    mp["01111110"] = "2";
    mp["01111111"] = "1";
    mp["100"] = "9-12";
    mp["1010"] = "7-8";
    mp["10110"] = "5-6";
    mp["101110"] = "4";
    mp["1011110"] = "3";
    mp["10111110"] = "2";
    mp["10111111"] = "1";
    mp["1100"] = "5-6";
    mp["11010"] = "4";
    mp["110110"] = "3";
    mp["1101110"] = "2";
    mp["1101111"] = "1";
    mp["11100"] = "3";
    mp["111010"] = "2";
    mp["111011"] = "1";
    mp["11110"] = "2";
    mp["11111"] = "1";
    map<string, int> pl;
    pl["1"] = 0;
    pl["2"] = 1;
    pl["3"] = 2;
    pl["4"] = 3;
    pl["5-6"] = 4;
    pl["7-8"] = 5;
    pl["9-12"] = 6;
    pl["13-16"] = 7;
    vector<pr> a(16);
    for (auto &it : a) {
        cin >> it.name >> it.bt;
        it.place = mp[it.bt];
    }
    sort(a.begin(), a.end(), [&pl] (const pr &lhs, const pr &rhs) {return pl[lhs.place] < pl[rhs.place];});
    sort(a.begin() + 4, a.begin() + 6, [] (const pr &lhs, const pr &rhs) {return lhs.name < rhs.name;});
    sort(a.begin() + 6, a.begin() + 8, [] (const pr &lhs, const pr &rhs) {return lhs.name < rhs.name;});
    sort(a.begin() + 8, a.begin() + 12, [] (const pr &lhs, const pr &rhs) {return lhs.name < rhs.name;});
    sort(a.begin() + 12, a.begin() + 16, [] (const pr &lhs, const pr &rhs) {return lhs.name < rhs.name;});
    for (auto &it : a) {
        cout << it.place << ' ' << it.name << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
        solve();
}
