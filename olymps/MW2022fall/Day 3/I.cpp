#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;

void fft (vector<complex<double>>& a, bool invert) {
    const int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap (a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2*M_PI/len * (invert ? -1 : 1);
        complex<double> wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            complex<double> w(1);
            for (int j = 0; j < len / 2; ++j) {
                complex<double> u = a[i+j], v = a[i+j+len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i = 0; i < n; ++i)
            a[i] /= n;
}

template <typename T>
void fft_multiply(const vector<int>& a, const vector<int>& b, vector<T>& res) {
    vector<complex<double>> fa(a.begin(), a.end());
    vector<complex<double>> fb(b.begin(), b.end());
    size_t n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft (fa, false);
    fft (fb, false);
    for (size_t i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, true);
    res.resize(a.size() + b.size() - 1);
    for (size_t i = 0; i < res.size(); ++i) {
        if (fa[i].real() >= 0)
            res[i] = T(fa[i].real() + 0.5);
        else
            res[i] = -T(abs(fa[i].real()) + 0.5);
    }
}

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    map<char, vector<int>> ms1, ms2;
    ms1['A'].assign(n, 0); ms1['G'].assign(n, 0);
    ms1['C'].assign(n, 0); ms1['T'].assign(n, 0);
    ms2['A'].assign(n, 0); ms2['G'].assign(n, 0);
    ms2['C'].assign(n, 0); ms2['T'].assign(n, 0);
    for (int i = 0; i < n; i++) {
        ms1[s1[i]][i] = 1;
        ms2[s2[i]][i] = 1;
    }

    vector<int> a(2*n), b(2*n);
    vector<int> ca, cc, cg, ct;
    for (int i = 0; i < n; i++) {
        a[i] = ms1['A'][n-i-1];
        b[i] = b[n+i] = ms2['A'][i];
    }
    fft_multiply(a, b, ca);

    for (int i = 0; i < n; i++) {
        a[i] = ms1['C'][n-i-1];
        b[i] = b[n+i] = ms2['C'][i];
    }
    fft_multiply(a, b, cc);

    for (int i = 0; i < n; i++) {
        a[i] = ms1['G'][n-i-1];
        b[i] = b[n+i] = ms2['G'][i];
    }
    fft_multiply(a, b, cg);

    for (int i = 0; i < n; i++) {
        a[i] = ms1['T'][n-i-1];
        b[i] = b[n+i] = ms2['T'][i];
    }
    fft_multiply(a, b, ct);

    int ans = 0, pos;
    for (int i = 2*n-2; i >= n-1; i--) {
        if (ans < ca[i]+cc[i]+cg[i]+ct[i]) {
            ans = ca[i]+cc[i]+cg[i]+ct[i];
            pos = 2*n-2 - i + 1;
        }
        ans = max(ans, ca[i]+cc[i]+cg[i]+ct[i]);
    }
    cout << ans << ' ' << pos << '\n';
}