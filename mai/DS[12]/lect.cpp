#include <>

struct tree {
    int get(int l, int r) {
        return  get(0, 0, n-1, l ,r);
    }
    int set(int p, int x) {
        set(0, 0, n-1, p, x);
    }
    void set(int id, int sl, int sr, int p, int x) {
        if (sl == sr) {
            data[id] += x;
            return;
        }
        int m = (sl + sr) / 2;
        if (p <= m) {
            set(id*2+1, sl, m, p, x);
        }
        else {
            set(id*2+2, m+1, sr, p, x);
        }
        data[id] = data;
        /////////////////////////////////////////
        int add(int id. int sl, int sr, int ql, int qr, int x) {
            if ((ql <= sl) && (sr <= qr)) {
                data[id] += x;
                return;
            }
            int m = (sl + sr) / 2;
            if (ql <= m) {
                add(id*2+2, m+1, sr, ql, qr, x);
            }
        }
        int get(int id, int sl, int sr, int p) {
            if (sl == sr) {
                return data[]
            }
        }
    }
};
