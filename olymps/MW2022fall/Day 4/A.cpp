#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

struct SuffAutom {
    struct State {
        int len, link;
        map<char,int> next;

    };
    vector<State> st;
    int last;

    SuffAutom() : st(1), last(0) {
        st[0].len = 0;
        st[0].link = -1;
    }
    SuffAutom(const string& s) : SuffAutom() {
        for (char c : s) sa_extend(c);
    }

    void sa_extend (char c) {
        int cur = st.size();
        st.emplace_back();
        st[cur].len = st[last].len + 1;
        int p;
        for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
            st[p].next[c] = cur;
        if (p == -1)
            st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len)
                st[cur].link = q;
            else {
                int clone = st.size();
                st.emplace_back();
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                for (; p != -1 && st[p].next[c] == q; p = st[p].link)
                    st[p].next[c] = clone;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    bool contains(const string& s) {
        int cur = 0;
        for (char c : s) {
            if (st[cur].next.contains(c))
                cur = st[cur].next[c];
            else return false;
        }
        return true;
    }
    void add(const string& s) {
        for (char c : s) sa_extend(c);
    }
};

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    char type;
    string s;
    SuffAutom sa;
    while (cin >> type >> s) {
        for (auto &&c : s)
            c = tolower(c);
        if (type == 'A')
            sa.add(s);
        else
            cout << (sa.contains(s) ? "YES" : "NO") << '\n';
    }    
}