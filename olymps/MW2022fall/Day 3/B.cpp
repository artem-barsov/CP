#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void fft (vector<complex<double>> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2.0*M_PI/(double)len * (invert ? -1 : 1);
		complex<double> wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			complex<double> w (1);
			for (int j=0; j<len/2; ++j) {
				complex<double> u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

template <typename T>
void fft_multiply(const vector<int> & a, const vector<int> & b, vector<T> & res) {
	vector<complex<double>> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
	res.resize (a.size() + b.size() - 1);
	for (size_t i=0; i<res.size(); ++i) {
        if (fa[i].real() >= 0)
		    res[i] = (T)(fa[i].real() + 0.5);
        else
		    res[i] = -(T)(abs(fa[i].real()) + 0.5);
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    string s;
    cin >> s;
    vector<int> a(s.length());
    for (int i = 0; i < s.length(); i++)
        a[i] = s[i] - '0';
    vector<ll> a2;
    fft_multiply(a, a, a2);
    ll ans = 0;
    for (int i = 0; i < a2.size(); i += 2) {
        if (a[i/2] == 1)
            ans += (a2[i] - 1) / 2;
    }
    cout << ans << '\n';
}