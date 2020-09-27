#include <bits/stdc++.h>

using namespace std;

struct Tfentree {
    std::vector<long long> t;
    long long n;
    void init (long long nn) {
    	n = nn;
    	t.assign (n, 0);
    }
    long long sum (long long r) {
    	long long result = 0;
    	for (; r >= 0; r = (r & (r+1)) - 1)
    		result += t[r];
    	return result;
    }
    void inc (long long i, long long delta) {
    	for (; i < n; i = (i | (i+1)))
    		t[i] += delta;
    }
    long long sum (long long l, long long r) {
    	return sum (r) - sum (l-1);
    }
    void init (vector<long long> a) {
    	init ((long long) a.size());
    	for (unsigned i = 0; i < a.size(); i++)
    		inc (i, a[i]);
    }
};

int main(long long argc, char const *argv[]) {
    long long n, y;
    std::vector<long long> a;
    std::string q;
    std::cin >> n >> y >> q;
    long long c = 0;
    for (long long i = 0; i < n; i++) {
        if (q[i] == '+') c++;
        else if (q[i] == '?') a.push_back(c);
    }
    Tfentree tree;
    tree.init(a);

    long long vars = 0;
    std::vector<long long> sums;
    while (vars < (1<<a.size())) {
        std::vector<long long> v = a;
        Tfentree tmptree;
        tmptree.init(v);
        for (long long i = v.size(); i >= 0; i--) {
            if (vars & (1<<i)) {
                for (long long j = i; j < v.size(); j++) tree.inc(j, -v[i]);
                tree.inc(i, y);
            }
        }
        sums.push_back(tree.sum(v.size()-1));
        vars++;
    }
    sort(sums.begin(), sums.end());
    std::cout << sums[0] << '\n';
}
