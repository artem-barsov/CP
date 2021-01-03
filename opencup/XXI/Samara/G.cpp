#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    std::string s;
    int k;
    std::cin >> s >> k;
    stack<pair<char, int> > st;
    st.push({s[s.length()-k], s.length()-k});
    for (int i = st.top().second; i >= 0; --i) {
        if (s[i] <= st.top().first) {
            st.push({s[i], i});
        }
    }
    std::cout << st.top().first;
    st.pop();
    for (int i = k-1; i > 0; --i) {
        if (st.empty() || (s[s.length()-i] < st.top().first)) {
            std::cout << s.substr(s.length()-i);
            break;
        }
        std::cout << st.top().first;
        st.pop();
    }
    std::cout << '\n';
}
a (b) a cabadaba
