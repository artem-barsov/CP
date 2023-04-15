#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
const int N = 'i' - 'a' + 1;

std::ostream& operator<< (std::ostream& os, std::bitset<N> adj[N]) {
    for (int i = 0; i < N; i++) {
        os << char('a' + i) << " : ";
        for (int j = 0; j < N; j++) {
            os << (adj[i][j] ? char('a'+j) : '.');
        }
        std::cout << '\n';
    }
    return os;
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    std::string s;
    std::cin >> s;
    std::string sa = s.substr(0, s.length() / 2);
    std::string sb = s.substr((s.length() + 1) / 2);
    reverse(sb.begin(), sb.end());
    std::bitset<N> adj[N];
    int nEdges = 0;
    for (int i = 0; i < sa.size(); i++) {
        if (sa[i] == sb[i]) continue;
        if (!adj[sa[i]-'a'][sb[i]-'a']) {
            adj[sa[i]-'a'][sb[i]-'a'] = true;
            adj[sb[i]-'a'][sa[i]-'a'] = true;
            nEdges++;
        }
    }
    std::cout << nEdges << '\n';
    std::cout << adj << '\n';
    int ans = 0;
    while (true) {
        std::cout << "/* message */" << '\n';
        int i, j;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (adj[i][j]) break;
        if (i == N) break;
        adj[i] |= adj[j];
        adj[j].reset();
        for (int k = 0; k < N; k++) adj[k][j] = false;
        ans++;
    }
    std::cout << ans << '\n';
}
