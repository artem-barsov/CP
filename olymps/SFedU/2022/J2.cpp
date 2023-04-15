#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
const int N = 'z' - 'a' + 1;

auto edge_todel(std::set<std::pair<int, int> >& edges, std::bitset<N> adj[N])
    -> decltype(edges.begin())
{
    auto ret = edges.begin();
    int max_cnt = 0;
    // for (auto& edge : edges) {
    for (auto edge = edges.begin(); edge != edges.end(); edge++) {
        auto [u, v] = *edge;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (i == u || i == v) continue;
            if (adj[i][u] && adj[i][v]) cnt++;
        }
        if (max_cnt < cnt) {
            ret = edge;
            max_cnt = cnt;
        }
    }
    return ret;
}

std::ostream& operator<<(std::ostream& os, std::bitset<N> adj[N]) {
    for (int i = 0; i < N; i++)
        os << adj[i] << '\n';
    return os;
}

template <typename It>
void remove_edge(std::set<std::pair<int, int> >& edges,
    std::bitset<N> adj[N], It iter)
{
    auto [u, v] = *iter;
    edges.erase(iter);
    adj[u] |= adj[v];
    adj[v].reset();
    printf("removed %c %c\n", u+'a', v+'a');
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
    std::vector<int> a, b;
    for (int i = 0; i < sa.size(); i++) {
        if (sa[i] != sb[i]) {
            a.push_back(sa[i] - 'a');
            b.push_back(sb[i] - 'a');
        }
    }
    std::set<std::pair<int, int> > edges;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        edges.emplace(a[i], b[i]);
    }
    std::bitset<N> adj[N];
    for (auto [u, v] : edges) {
        adj[u][v] = true;
        adj[v][u] = true;
    }
    std::cout << adj << '\n';
    int ans = 0;
    while (!edges.empty()) {
        // std::cout << edges.size() << '\n';
        remove_edge(edges, adj, edge_todel(edges, adj));
        ans++;
    }
    std::cout << ans << '\n';
}
