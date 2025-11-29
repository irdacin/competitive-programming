#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << (x) << endl

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) { 
  os << "(" << _p.first << ", " << _p.second << ")"; return os; 
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for (auto& _x : _v) { is >> _x; } return is;
}
template <typename Ch, typename Tr, typename Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, const Container& _c) {
  size_t _i = 0; os << "{ "; for (const auto& _x : _c) { os << (_i++ ? ", " : "") << _x; }
  return os << " }";
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void prinsp(T&& A, char sp = ' ') { prin(A, sp); }

template <typename T> using vec = vector<T>;
template <typename T> struct vvec : vec<vec<T>> {
  using vec<vec<T>>::vec;
  vvec(size_t N = 0, size_t M = 0, const T& _init_value = T())
    : vec<vec<T>>(N, vec<T>(M, _init_value)) {}
};
template <typename T> struct vvvec : vec<vvec<T>> {
  using vec<vvec<T>>::vec;
  vvvec(size_t N = 0, size_t M = 0, size_t K = 0, const T& _init_value = T())
    : vec<vvec<T>>(N, vvec<T>(M, K, _init_value)) {}
};

using pii = pair<int, int>;
using iii = tuple<int, int, int>;
#define fi first
#define se second
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;
const double EPS = 1e-9;

struct mint {
  using u128 = __uint128_t;
  static inline uint64_t mod, mu;
  uint64_t val;

  mint() : val(0) {}
  mint(int v) { if (v < 0) (v %= (int)mod) += mod; val = reduce(v); }
  explicit operator int() const { return val; }
  static void set_mod(int m) { mod = m, mu = -1ULL / m; }
  static inline uint64_t reduce(u128 x) {
    u128 q = (x * mu) >> 64;
    u128 r = x - q * mod;
    return r >= mod ? r - mod : r;
  }

  mint& operator+=(const mint& other) { return (val += other.val) >= mod ? val -= mod : val, *this; }
  mint& operator-=(const mint& other) { return (val -= other.val) >= mod ? val += mod : val, *this; }
  mint& operator*=(const mint& other) { return val = reduce(u128(val) * other.val), *this; }
  mint& operator/=(const mint& other) { return *this *= inv(other); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  mint operator++(int32_t) { mint mi = *this; ++*this; return mi; }
  mint operator--(int32_t) { mint mi = *this; --*this; return mi; }
  mint operator+() const { return *this; }
  mint operator-() const { return mint() -= *this; }
  friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
  friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
  friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
  friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }

  friend mint pow(mint mi, int k) { mint r(1); for(; k > 0; k >>= 1, mi *= mi) if(k & 1) r *= mi; return r; }
  static int inv(int mi, int mod) { return mi == 1 ? 1 : mod - inv(mod % mi, mi) * mod / mi; }
  static mint inv(mint mi) { 
    return pow(mi, mod - 2);
    // if(gcd(mi.val, mod) != 1) return -1;
    return mint(inv(mi.val, mod)); // use this inv if mod is not prime
  }

  bool operator==(const mint& other) const { return val == other.val; }
  bool operator!=(const mint& other) const { return val != other.val; }
  friend istream& operator>>(istream& is, mint& mi) { int x; is >> x; mi = mint(x); return is; }
  friend ostream& operator<<(ostream& os, const mint& mi) { return os << mi.val; }
};

const int MAXN = 1e6;
mint fact[MAXN + 1];

void precompute() {
  fact[0] = 1;
  for(int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i;
}

mint C(int n, int k) {
  if(k > n) return 0;
  return fact[n] / (fact[k] * fact[n - k]);
}

void solve() {
  int a, b; cin >> a >> b;
  print(C(a, b));
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  mint::set_mod(1'000'000'007);
  precompute();
  int t; cin >> t; while(t--)
  solve();
}