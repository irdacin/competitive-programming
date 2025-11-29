#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << x << endl

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& _v) {
  for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T&& A, const char* sp = " ") { prin(A, sp); }

template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
  using vec<vec<T>>::vec;
  vvec(int N = 0, int M = 0, const T& _init_value = T())
    : vec<vec<T>>(N, vec<T>(M, _init_value)) {}
};
template <typename T> struct vvvec : vec<vvec<T>> {
  using vec<vvec<T>>::vec;
  vvvec(int N = 0, int M = 0, int K = 0, const T& _init_value = T())
    : vec<vvec<T>>(N, vvec<T>(M, K, _init_value)) {}
};

using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;

struct Barrett {
  using u128 = __uint128_t;
  static inline u128 mod, mu;

  static void set_mod(int m) { mod = m, mu = -1 / mod; }
  operator int() const { return mod; }
  friend auto operator%(auto x, const Barrett) { return reduce(x); }

  static u128 reduce(u128 val) {
    u128 a = val * uint64_t(mu);
    u128 b = val * (mu >> 64);
    u128 c = mu * (val >> 64);
    u128 d = (val >> 64) * (mu >> 64);
    u128 q = d + ((b + c + (a >> 64)) >> 64);
    u128 r = val - q * mod;
    if(r >= mod) r -= mod;
    return r;
  }
};

template<auto M>
struct ModInt {
  int val;
  ModInt(int _val = 0) : val(_val % M) { if(val < 0) val += M; }
  operator int() const { return val; }

  ModInt& operator+=(const ModInt& mi) { return (val += mi) >= M ? val -= M : val, *this; }
  ModInt& operator-=(const ModInt& mi) { return (val -= mi) < 0 ? val += M : val, *this; }
  ModInt& operator*=(const ModInt& mi) { return (val *= mi) %= M, *this; }
  ModInt& operator/=(const ModInt& mi) { return *this *= inv(mi); }
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  ModInt operator-() const { return ModInt() -= *this; }
  ModInt operator+(const auto& mi) const { return ModInt(*this) += mi; }
  ModInt operator-(const auto& mi) const { return ModInt(*this) -= mi; }
  ModInt operator*(const auto& mi) const { return ModInt(*this) *= mi; }
  ModInt operator/(const auto& mi) const { return ModInt(*this) /= mi; }
  ModInt operator++(int32_t) { ModInt mi = *this; ++*this; return mi; }
  ModInt operator--(int32_t) { ModInt mi = *this; --*this; return mi; }

  friend ModInt pow(ModInt mi, int k) { ModInt r = 1; for(; k > 0; k /= 2, mi *= mi) if(k & 1) r *= mi; return r; }
  static int inv(ModInt mi) { return pow(mi, M - 2); }
  static int inv(int mi, int mod) { return mi == 1 ? 1 : mod - inv(mod % mi, mi) * mod / mi; }

  friend istream& operator>>(istream& is, ModInt& mi) { is >> mi.val; mi = ModInt(mi.val); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& mi) { return os << mi.val; }
};

using mint = ModInt<Barrett{}>;

void solve() {
  int a, b, c; cin >> a >> b >> c;

  Barrett::set_mod(MOD - 1);
  mint x = pow(mint(b), c);

  Barrett::set_mod(MOD);
  mint ans = pow(mint(a), x);
  print(ans);
}

signed main() {
  fastio;
  // #undef endl

  // precompute();
  // cout << fixed << setprecision(6);
  int t; cin >> t; while(t--)
  solve();
}