#include <bits/stdc++.h>
#ifndef LOCAL
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif

using namespace std;
using ll = long long;

void fft(vector<complex<double>>& a, bool invert) {
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

template <unsigned C>
class BigInteger {
private:
    const int DIGIT_LEN = C; // длина разряда в 10 СС
    const int BASE = invoke([](unsigned c) constexpr { 
        unsigned long long x = 1;
        while (c--) x *= 10;
        return x;
    }, C); // база внутренней СС
    std::vector<int> digits;
    bool isNegative;
public:
    BigInteger() : digits(1), isNegative(false) { }
    BigInteger(const int other) : BigInteger(to_string(other)) { }
    BigInteger(std::string val) : digits(val.length() / DIGIT_LEN + 1), isNegative(false) {
        if (val[0] == '-') {
            this->isNegative = true;
            val[0] = '0';
        }
        for (int i = 0, offs = DIGIT_LEN; (val.length()>=offs)&&(i < digits.size()); i++, offs += DIGIT_LEN) {
            digits[i] = atoi(val.c_str() + val.length()-offs);
            *(val.end()-offs) = '\0';
        }
        digits.back() = atoi(val.c_str());
        while ((digits.back() == 0) && (digits.size() > 1))
            digits.pop_back();
    }
    BigInteger(const BigInteger<C>& other) {
        this->digits = other.digits;
        this->isNegative = other.isNegative;
    }
    BigInteger<C>& operator= (BigInteger<C>&& other) {
        this->digits.swap(other.digits);
        this->isNegative = other.isNegative;
        return *this;
    }
    BigInteger<C>& operator= (const BigInteger<C>& other) {
        this->digits = other.digits;
        this->isNegative = other.isNegative;
        return *this;
    }
    BigInteger<C>& operator+= (const BigInteger<C>& other) {
        if (this->digits.size() < other.digits.size())
            this->digits.resize(other.digits.size());
        bool k = 0;
        for (size_t i = 0; i < other.digits.size(); i++) {
            this->digits[i] += other.digits[i] + k;
            k = this->digits[i] >= BASE;
            if (k) this->digits[i] -= BASE;
        }
        if (k) {
            for (size_t i = other.digits.size(); ; i++) {
                if (i == this->digits.size()) {
                    this->digits.push_back(k);
                    break;
                }
                if (this->digits[i] < BASE - k) {
                    this->digits[i] += k;
                    break;
                }
                this->digits[i] = 0;
            }
        }
        return *this;
    }
    BigInteger<C>& operator-= (const BigInteger<C>& other) {
        if (this->digits.size() < other.digits.size()) throw "Error";
        bool k = 0;
        for (size_t i = 0; i < other.digits.size(); i++) {
            this->digits[i] -= other.digits[i] + k;
            k = this->digits[i] < 0;
            if (k) this->digits[i] += BASE;
        }
        if (k) {
            for (size_t i = other.digits.size(); i < this->digits.size(); i++) {
                if (this->digits[i] > 0) {
                    this->digits[i] -= k;
                    k = 0;
                    break;
                }
                this->digits[i] = BASE - 1;
            }
        }
        if (k) throw "Error";
        while ((this->digits.size() > 1) && (this->digits.back() == 0)) {
            this->digits.pop_back();
        }
        return *this;
    }
    BigInteger<C>& operator*= (const BigInteger<C>& other) {
        this->isNegative = this->isNegative ^ other.isNegative;
        if (other.digits.size() == 1)
            return *this *= other.digits[0];
        if (this->digits.size() == 1) {
            this->digits = (other * this->digits[0]).digits;
            return *this;
        }
        std::vector<long long> res;
        fft_multiply(this->digits, other.digits, res);
        this->digits.resize(res.size());
        long long carry = 0;
        for (size_t i = 0; i < res.size(); ++i) {
            this->digits[i] = (res[i] + carry) % this->BASE;
            carry = (res[i] + carry) / this->BASE;
        }
        if (carry) this->digits.push_back(carry);
        while ((this->digits.size() > 1) && (this->digits.back() == 0))
            this->digits.pop_back();
        return *this;
    }
    BigInteger<C>& operator*= (const int other) {
        this->isNegative = this->isNegative ^ (other < 0);
        int k = 0;
        for (size_t i = 0; i < this->digits.size(); i++) {
            auto qurem = lldiv(this->digits[i]*1ll*other + k, BASE);
            this->digits[i] = qurem.rem;
            k = qurem.quot;
        }
        if (k) this->digits.push_back(k);
        while ((this->digits.size() > 1) && (this->digits.back() == 0)) {
            this->digits.pop_back();
        }
        return *this;
    }
    BigInteger<C>& operator/= (BigInteger<C>& other) {
        if (other.digits.size() == 1) {
            return *this /= other.digits[0];
        }
        *this *= BASE;
        other *= BASE;
        size_t u_size = this->digits.size();
        size_t v_size = other.digits.size();
        if (u_size < v_size) {
            this->digits = std::vector<int>(1);
            return *this;
        }
        std::vector<int> res(u_size - v_size + 1);
        int d = BASE / (other.digits.back() + 1);
        *this *= d;
        other *= d;
        if (this->digits.size() == u_size)
            this->digits.push_back(0);
        for (int j = u_size - v_size; j >= 0; --j) {
            auto qr = lldiv(this->digits[j+v_size]*1ull*BASE + this->digits[j+v_size-1], other.digits[v_size-1]);
            int q = qr.quot;
            int r = qr.rem;
            if (q == BASE || q*1ull*other.digits[v_size-2] > BASE*1ull*r + this->digits[j+v_size-2]) {
                --q;
                r += other.digits[v_size-1];
            }
            if (r < BASE && (q == BASE || q*1ull*other.digits[v_size-2] > BASE*1ull*r + this->digits[j+v_size-2])) {
                --q;
                r += other.digits[v_size-1];
            }
            BigInteger<C> qv = other * q;
            bool k = 0;
            int u_to = j + v_size;
            int v_to = qv.digits.size()-1;
            while (this->digits[u_to] == 0 && u_to > j)
                --u_to;
            while (qv.digits[v_to] == 0 && v_to > 0)
                --v_to;
            if ((u_to - j) != v_to) {
                k = (u_to - j) < v_to;
            }
            else {
                if (!k) {
                    for (; j < u_to; --u_to, --v_to) {
                        if (this->digits[u_to] != qv.digits[v_to]) {
                            k = this->digits[u_to] < qv.digits[v_to];
                            break;
                        }
                    }
                }
                if (!k) k = this->digits[j] < qv.digits[0];
            }
            if (k) {
                --q;
                qv = other * q;
                k = 0;
            }
            for (int v_at = 0, u_at = j; v_at < qv.digits.size(); ++u_at, ++v_at) {
                this->digits[u_at] -= qv.digits[v_at] + k;
                k = this->digits[u_at] < 0;
                if (k) this->digits[u_at] += BASE;
            }
            res[j] = q;
        }
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }
        this->digits.swap(res);
        return *this;
    }
    BigInteger<C>& operator/= (const int other) {
        if (!other) throw "Error";
        int k = 0;
        for (int i = this->digits.size()-1; i >= 0; i--) {
            auto qurem = lldiv(this->digits[i] + k*1ull*BASE, other);
            this->digits[i] = qurem.quot;
            k = qurem.rem;
        }
        while ((this->digits.size() > 1) && (this->digits.back() == 0)) {
            this->digits.pop_back();
        }
        return *this;
    }
    BigInteger<C>& operator^= (BigInteger<C>& other) {
        if (other.digits.size() == 1) {
            return *this ^= other.digits[0];
        }
        BigInteger<C> res;
        res.digits[0] = 1;
        while (other.digits.size() > 1 || other.digits[0]) {
            if (other.digits[0] & 1)
                res *= *this;
            *this *= *this;
            other /= 2;
        }
        this->digits.swap(res.digits);
        return *this;
    }
    BigInteger<C>& operator^= (int other) {
        if (this->digits.size() == 1 && !this->digits[0] && !other)
            throw "Error";
        BigInteger<C> res;
        res.digits[0] = 1;
        while (other) {
            if (other & 1)
                res *= *this;
            *this *= *this;
            other >>= 1;
        }
        this->digits.swap(res.digits);
        return *this;
    }
    friend BigInteger operator+ (BigInteger<C> lhs, BigInteger<C>& rhs) {
        return std::move(lhs += rhs);
    }
    friend BigInteger operator- (BigInteger<C> lhs, const BigInteger<C>& rhs) {
        return std::move(lhs -= rhs);
    }
    friend BigInteger operator* (BigInteger<C> lhs, BigInteger<C>& rhs) {
        return std::move(lhs *= rhs);
    }
    friend BigInteger operator* (BigInteger<C> lhs, int rhs) {
        return std::move(lhs *= rhs);
    }
    friend BigInteger operator* (int lhs, BigInteger<C> rhs) {
        return std::move(rhs *= lhs);
    }
    friend BigInteger operator/ (BigInteger<C> lhs, BigInteger<C>& rhs) {
        return std::move(lhs /= rhs);
    }
    friend BigInteger operator/ (BigInteger<C> lhs, int rhs) {
        return std::move(lhs /= rhs);
    }
    friend BigInteger operator^ (BigInteger<C> lhs, BigInteger<C>& rhs) {
        return std::move(lhs ^= rhs);
    }
    friend BigInteger operator^ (BigInteger<C> lhs, int rhs) {
        return std::move(lhs ^= rhs);
    }
    friend std::ostream& operator<< (std::ostream& out, const BigInteger<C>& bi) {
        if (bi.isNegative && bi != 0) out << '-';
        for (int i = bi.digits.size()-1; i >= 0; i--) {
            if (i != bi.digits.size()-1) {
                out << std::setfill('0') << std::setw(bi.DIGIT_LEN);
            }
            out << bi.digits[i];
        }
        return out;
    }
    friend std::istream& operator>> (std::istream& in, BigInteger<C>& bi) {
        std::string tmp;
        in >> tmp;
        bi = BigInteger<C>(tmp);
        return in;
    }
    friend bool operator< (const BigInteger<C>& lhs, const BigInteger<C>& rhs) {
        if (lhs.digits.size() != rhs.digits.size())
            return lhs.digits.size() < rhs.digits.size();
        for (int i = lhs.digits.size()-1; i >= 0; i--) {
            if (lhs.digits[i] != rhs.digits[i])
                return lhs.digits[i] < rhs.digits[i];
        }
        return false;
    }
    friend bool operator> (const BigInteger<C>& lhs, const BigInteger<C>& rhs) {
        return rhs < lhs;
    }
    friend bool operator<= (const BigInteger<C>& lhs, const BigInteger<C>& rhs) {
        return !(lhs > rhs);
    }
    friend bool operator>= (const BigInteger<C>& lhs, const BigInteger<C>& rhs) {
        return !(lhs < rhs);
    }
    friend bool operator== (const BigInteger<C>& lhs, const BigInteger<C>& rhs) {
        if (lhs.digits.size() != rhs.digits.size())
            return false;
        for (size_t i = 0; i < lhs.digits.size(); i++) {
            if (lhs.digits[i] != rhs.digits[i])
                return false;
        }
        return true;
    }
    friend bool operator!= (const BigInteger<C>& lhs, const BigInteger<C>& rhs) {
        return !(lhs == rhs);
    }
};

int main(int argc, char const *argv[]) {
#ifndef LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    string s;
    cin >> s;
    bool isNeg = s[0] == '-';
    if (s[0] == '-' || s[0] == '+')
        s = s.substr(1);
    if (!isNeg) {
        int l = 0;
        while (l < s.length() && s[l] == '0') l++;
        if (l == s.length())
            cout << 0 << '\n';
        else
            cout << s.substr(l) << '\n';
        return 0;
    }
    
    if (isNeg && s.length() > 1) {
        int a = s[0] - '0';
        int l = 1;
        while (l < s.length() && s[l] == '0') l++;
        if (a == 0) {
            if (l == s.length())
                cout << 0 << '\n';
            else
                cout << s.substr(l) << '\n';
            return 0;
        }
        if (s.length() == 2) {
            int b = s[1] - '0';
            if (b == 0) {
                cout << 0 << '\n';
                return 0;
            }
            int ans1 = -a / b;
            int ans2 = b - a;
            cout << max(ans1, ans2) << '\n';
            return 0;
        }

        if (s[1] == '0') {
            cout << s.substr(l) << '\n';
            return 0;
        }
        else {
            BigInteger<6> sl = s.substr(l);
            cout << sl - a << '\n';
        }
        return 0;
    }
    
    cout << (s == "0" ? "" : "-") << s << '\n';
}