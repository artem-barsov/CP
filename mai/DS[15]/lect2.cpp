// g++ -g3 lect.cpp
// valgrind ./a.out
// g++ -D debug lect.cpp
// g++ -D_GLIBCXX_DEGUB A.cpp
#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
    int n;
    std::vector<int> data;
    std::vector<int> delay;

    void add(int id, int sl, int sr, int ql, int qr, int x) {
        if ((ql <= sl) && (sr <= qr)) {
            delay[id] += x;
            return;
        }
        push(id, sl, sr);
        int m = (sl + sr) / 2;
        if (ql <= m) {
            add(id*2+1, sl, m, ql, qr, x);
        }
        if (m < qr) {
            add(id*2+2, m+1, sr, ql, qr, x);
        }
        data[id] = max(data[id*2+1], data[id*2+2]);
        // data[id] = max(get(id*2+1, sl, m, sl, m), get(id*2+2, sr, m+1, sr, m+1));
    }

    void push(int id, int sl, int sr) {
        data[id] += delay[id];
        if (sl != sr) {
            delay[id*2+1] += delay[id];
            delay[id*2+2] += delay[id];
        }
        delay[id] = 0;
    }

    int get(int id, int sl, int sr, int ql, int qr) {
        push(id, sl, sr);
        if ((ql <= sl) && (sr <= qr)) {
            return data[id];
        }
        int m = (sl + sr) / 2;
        if (qr <= m) {
            return get(id*2+1, sl, m, ql, qr);
        }
        if (m < ql) {
            return get(id*2+2, m+1, sr, ql, qr);
        }
        return max(get(id*2+1, sl, m, ql, qr), get(id*2+2, m+1, sr, ql, qr));
    }
};


int main(int argc, char const *argv[]) {

}
