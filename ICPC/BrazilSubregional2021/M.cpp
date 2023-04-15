#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Graph = vector<vector<int>>;

const int N = 1'000'000;

bool killed[N];
vector<int> g[N];
int visited[N];

stack<int> st;
int curr, n;

void init() {
    curr = 1;
    n = 1;
}

void push(int u) {
    g[u].push_back(n + 1);
    ++n;
}

void traverse() {
    if (!g[curr].empty()) {
        st.push(curr);
        ++visited[curr];

        int v = g[curr].front();
        curr = v;

        if (killed[v]) {
            traverse();
        }

        return;
    }

    while (visited[st.top()] == g[st.top()].size()) {
        st.pop();
    }

    int v = st.top();

    curr = g[v][visited[v]];
    ++visited[v];

    if (killed[curr]) {
        traverse();
    }
}

int kill(int u) {
    killed[u] = true;
    if (u != curr) {
        return curr;
    }

    traverse();
    return curr;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            push(x);
        } else {
            cout << kill(x) << '\n';
        }
    }
}
