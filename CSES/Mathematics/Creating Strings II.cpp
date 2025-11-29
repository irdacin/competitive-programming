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
  int _i = 0; os << "{ "; for (const auto& _x : _c) { os << (_i++ ? ", " : "") << _x; }
  return os << " }";
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T&& A, char sp = ' ') { prin(A, sp); }

template <typename T> using vec = vector<T>;
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
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;

struct DynModInt {
  using u128 = __uint128_t;
  static inline int mod, mu;
  int val;
  DynModInt() : val(0) {}
  DynModInt(int v) { if(v < 0) (v += mod) %= mod; val = reduce(v); }
  explicit operator int() const { return val; }
  static void set_mod(int m) { mod = m, mu = (u128(1) << 64) / m + 1; }
  static inline int reduce(u128 x) { 
    int q = (u128(mu) * x) >> 64; 
    int r = x - u128(q) * mod;
    return r < 0 ? r + mod : r;
  }
  
  DynModInt& operator+=(const DynModInt& other) { return (val += other.val) >= mod ? val -= mod : val, *this; }
  DynModInt& operator-=(const DynModInt& other) { return (val -= other.val) < 0 ? val += mod : val, *this; }
  DynModInt& operator*=(const DynModInt& other) { return val = reduce(u128(val) * other.val), *this; }
  DynModInt& operator/=(const DynModInt& other) { return *this *= inv(other.val); }
  DynModInt& operator++() { return *this += 1; }
  DynModInt& operator--() { return *this -= 1; }
  DynModInt operator++(int32_t) { DynModInt mi = *this; ++*this; return mi; }
  DynModInt operator--(int32_t) { DynModInt mi = *this; --*this; return mi; }
  DynModInt operator+() const { return *this; }
  DynModInt operator-() const { return DynModInt() -= *this; }
  friend DynModInt operator+(const DynModInt& lhs, const DynModInt& rhs) { return DynModInt(lhs) += rhs; }
  friend DynModInt operator-(const DynModInt& lhs, const DynModInt& rhs) { return DynModInt(lhs) -= rhs; }
  friend DynModInt operator*(const DynModInt& lhs, const DynModInt& rhs) { return DynModInt(lhs) *= rhs; }
  friend DynModInt operator/(const DynModInt& lhs, const DynModInt& rhs) { return DynModInt(lhs) /= rhs; }
 
  friend DynModInt pow(DynModInt mi, int k) { DynModInt r = 1; for(; k > 0; k /= 2, mi *= mi) if(k & 1) r *= mi; return r; }
  static int inv(int mi, int mod) { return mi == 1 ? 1 : mod - inv(mod % mi, mi) * mod / mi; }
  static int inv(DynModInt mi) { 
    return (int) pow(mi, mod - 2);
    // if(gcd(mi.val, mod) != 1) return -1;
    return inv(mi.val, mod); // use this inv if mod is not prime
  }
 
  bool operator==(const DynModInt& other) const { return val == other.val; }
  bool operator!=(const DynModInt& other) const { return val != other.val; }
  friend istream& operator>>(istream& is, DynModInt& mi) { is >> mi.val; mi = DynModInt(mi.val); return is; }
  friend ostream& operator<<(ostream& os, const DynModInt& mi) { return os << mi.val; }
};

template<int M>
struct ModInt {
  int val;
  ModInt(int _val = 0) : val(_val % M) { if(val < 0) val += M; }
  explicit operator int() const { return val; }
 
  ModInt& operator+=(const ModInt& other) { return (val += other.val) >= M ? val -= M : val, *this; }
  ModInt& operator-=(const ModInt& other) { return (val -= other.val) < 0 ? val += M : val, *this; }
  ModInt& operator*=(const ModInt& other) { return (val *= other.val) %= M, *this; }
  ModInt& operator/=(const ModInt& other) { return *this *= inv(other.val); }
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  ModInt operator++(int32_t) { ModInt mi = *this; ++*this; return mi; }
  ModInt operator--(int32_t) { ModInt mi = *this; --*this; return mi; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt() -= *this; }
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }
 
  friend ModInt pow(ModInt mi, int k) { ModInt r = 1; for(; k > 0; k /= 2, mi *= mi) if(k & 1) r *= mi; return r; }
  static int inv(int mi, int mod) { return mi == 1 ? 1 : mod - inv(mod % mi, mi) * mod / mi; }
  static int inv(ModInt mi) { 
    return (int) pow(mi, M - 2);
    // if(gcd(mi.val, M) != 1) return -1;
    return inv(mi.val, M); // use this inv if M is not prime
  }
 
  bool operator==(const ModInt& other) const { return val == other.val; }
  bool operator!=(const ModInt& other) const { return val != other.val; }
  friend istream& operator>>(istream& is, ModInt& mi) { is >> mi.val; mi = ModInt(mi.val); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& mi) { return os << mi.val; }
};
 
// using mint = ModInt<1000000007>;
using mint = DynModInt;

const int MAXN = 1e6;
mint fact[MAXN + 1];
 
void precompute() {
  fact[0] = 1;
  for(int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i;
}

void solve() {
  string s; cin >> s;
  vec<int> freq(26);
  for(auto c : s) freq[c - 'a']++;
 
  mint ans = fact[len(s)];
  for(auto i : freq) ans /= fact[i];
  print(ans);
}

signed main() {
  fastio;
  // #undef endl
  
  mint::set_mod(1000000007);
  precompute();
  // cout << fixed << setprecision(6);
  // int t; cin >> t; while(t--)
  solve();
}