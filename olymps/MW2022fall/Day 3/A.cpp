#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
#define int long long

void fft1 (vector<complex<double>>& a, bool invert) {
	int n = (int) a.size();
	if (n == 1)  return;
	vector<complex<double>> a0 (n/2),  a1 (n/2);
	for (int i=0, j=0; i<n; i+=2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i+1];
	}
	fft1 (a0, invert);
	fft1 (a1, invert);
	double ang = 2*M_PI/n * (invert ? -1 : 1);
	complex<double> w (1),  wn (cos(ang), sin(ang));
	for (int i=0; i<n/2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i+n/2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2,  a[i+n/2] /= 2;
		w *= wn;
	}
}

void fft2 (vector<complex<double>> & a, bool invert) {
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
		double ang = 2*M_PI/len * (invert ? -1 : 1);
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

void multiply (const vector<int> & a, const vector<int> & b, vector<long long> & res) {
	vector<complex<double>> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
	// fft1 (fa, false),  fft1 (fb, false);
	fft2 (fa, false),  fft2 (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	// fft1 (fa, true);
	fft2 (fa, true);
	res.resize (a.size() + b.size() - 1);
	for (size_t i=0; i<res.size(); ++i) {
        if (fa[i].real() > 0)
		    res[i] = (long long)(fa[i].real() + 0.5);
        else
		    res[i] = -(long long)(abs(fa[i].real()) + 0.5);
    }
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto &&x : v) os << x << ' ';
	return os;
}

signed main(signed argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (auto&& x : a) cin >> x;
    int m;
    cin >> m;
    vector<int> b(m+1);
    for (auto&& x : b) cin >> x;
    vector<long long> res;
    multiply(a, b, res);
	cout << res.size() - 1 << ' ' << res << '\n';
}