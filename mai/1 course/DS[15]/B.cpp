#include <bits/stdc++.h>
#define ll long long
#define _CRT_DISABLE_PERFCRIT_LOCKS

using namespace std;

struct Tfentree {
    std::vector<ll> t;
    ll n;
    ll sum(ll r) {
    	ll result = 0;
    	for (; r >= 0; r = (r & (r+1)) - 1)
    		result += t[r];
    	return result;
    }
    ll sum(ll l, ll r) {
        return sum (r) - sum (l-1);
    }
    void add(ll i, ll delta) {
    	for (; i < n; i = (i | (i+1)))
    		t[i] += delta;
    }
    void init(ll nn) {
        n = nn;
        t.assign (n, 0);
    }
    void init(vector<ll> a) {
    	init ((ll) a.size());
    	for (unsigned i = 0; i < a.size(); i++)
    		add (i, a[i]);
    }
};

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    std::cin >> n;
    std::vector<ll> a(n);
    for (ll i = 0; i < n; i++) std::cin >> a[i];
    std::cin >> k;
    Tfentree baum;
    baum.init(a);
    for (ll i = 0; i < k; i++) {
        ll l, r, x;
        std::cin >> l >> r >> x;
        for (ll j = l; j <= r; j++) baum.add(j-1, x);
        std::cout << baum.sum(l-1, r-1) << '\n';
    }
}
