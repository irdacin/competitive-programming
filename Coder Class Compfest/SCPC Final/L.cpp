#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& _p) { is >> _p.first >> _p.second; return is; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U> _p) { os << _p.first << ' ' << _p.second; return os; }
template <typename T> istream& operator>>(istream& is, vector<T>& _v) { for(auto &_i : _v) is >> _i; return is; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) { for(auto &_i : _v) os << _i << " \n"[&_i == &_v.back()]; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const vector<pair<T, U>> _v) { for(auto _i : _v) os << _i << endl; return os; }
template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
    vvec(initializer_list<initializer_list<T>> _list) { for(const auto& _row : _list) this->emplace_back(_row); }
    vvec(int _n = 0, int _m = 0, const T& _init_value = T()) : vec<vec<T>>(_n, vec<T>(_m, _init_value)) {}
    friend ostream& operator<<(ostream &os, const vvec _v) { for(auto _i : _v) os << _i; return os; }
};
template <typename T> struct vvvec : vec<vvec<T>> {
    vvvec(initializer_list<initializer_list<initializer_list<T>>> _list) { for(const auto& _rows : _list) for(const auto& _row : _rows) this->emplace_back(_row); }
    vvvec(int _n = 0, int _m = 0, int _k = 0, const T& _init_value = T()) : vec<vvec<T>>(_n, vvec<T>(_m, _k, _init_value)) {}
    friend ostream& operator<<(ostream &os, const vvvec _v) { for(auto _i : _v) os << _i << endl; return os; }
};
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second

const int MOD = 998244353;
const int INF = 2e9;
const int MAXN = 2e5;

template<int M>
struct ModInt {
    int val;

    ModInt(int _val = 0) : val(_val % M) { if(val < 0) val += M; }

    ModInt operator-() const { return ModInt() -= *this; }
    ModInt operator+(const ModInt other) const { return ModInt(*this) += other; }
    ModInt operator-(const ModInt other) const { return ModInt(*this) -= other; }
    ModInt operator*(const ModInt other) const { return ModInt(*this) *= other; }
    ModInt operator/(const ModInt other) const { return ModInt(*this) /= other; }
    ModInt &operator+=(const ModInt other) { return (val += other.val) >= M ? val -= M : val, *this; }
    ModInt &operator-=(const ModInt other) { return (val -= other.val) < 0 ? val += M : val, *this; }
    ModInt &operator*=(const ModInt other) { return (val *= other.val) %= M, *this; }
    ModInt &operator/=(const ModInt other) { return (val *= inv(other)) %= M, *this; }
    ModInt &operator++() { return *this += 1; }
    ModInt &operator--() { return *this -= 1; }
    ModInt operator++(int32_t) { ModInt mi = *this; ++*this; return mi; }
    ModInt operator--(int32_t) { ModInt mi = *this; ++*this; return mi; }
    ModInt pow(ModInt mi, int k) const { return k == 0 ? 1 : pow(mi * mi, k / 2) * (k & 1 ? mi : 1); }
    int inv(ModInt mi) const { return pow(mi, M - 2).val; }
    int inv(int x, int m) const { return x == 1 ? 1 : m - inv(m % x, x) * m / x; } // use this for divisor if M is not prime

    bool operator==(const ModInt other) const { return val == other.val; }
    bool operator!=(const ModInt other) const { return val != other.val; }
    bool operator>=(const ModInt other) const { return val >= other.val; }
    bool operator<=(const ModInt other) const { return val <= other.val; }
    bool operator>(const ModInt other) const { return val > other.val; }
    bool operator<(const ModInt other) const { return val < other.val; }

    friend istream& operator>>(istream &is, ModInt &mi) { is >> mi.val; mi = ModInt(mi.val); return is; }
    friend ostream& operator<<(ostream &os, const ModInt &mi) { return os << mi.val; }
};

using mint = ModInt<MOD>;

mint fact[MAXN + 1];

void precompute(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= MAXN; i++) fact[i] = fact[i - 1] * i;
}

void solve(){
    int n; cin >> n;

    int cntOdd = 0, cntEven = 0;
    mint sumOdd = 0, sumEven = 0;

    for(int i = 0, a; i < n; i++){
        cin >> a;
        if(a & 1) cntOdd++, sumOdd += a;
        else cntEven++, sumEven += a;
    }

    if(cntEven == n) rcout(-1);

    mint P = 0;
    for(int even = 0; even <= cntEven; even++){
        mint count = 0;

        mint ways = fact[cntEven] / fact[cntEven - even]; 
        count += ways / cntEven * even * sumEven * cntOdd;
        count += ways * sumOdd;
        count *= fact[n - even - 1];

        P += count;
    }

    mint Q = fact[n];

    cout << P / Q;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    precompute();

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
    // solve();
}