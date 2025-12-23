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

template<auto M>
struct ModInt {
  int val;
  ModInt(int _val = 0) : val(_val % M) { if(val < 0) val += M; }
  explicit operator int() const { return val; }
 
  ModInt& operator+=(const ModInt& other) { return (val += other.val) >= M ? val -= M : val, *this; }
  ModInt& operator-=(const ModInt& other) { return (val -= other.val) < 0 ? val += M : val, *this; }
  ModInt& operator*=(const ModInt& other) { return val = val * other.val % M, *this; }
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
  static int inv(ModInt mi) { return (int) pow(mi, M - 2); }
  static int inv(int mi, int mod) { return mi == 1 ? 1 : mod - inv(mod % mi, mi) * mod / mi; } // use this for div if M is not prime
 
  bool operator==(const ModInt& other) const { return val == other.val; }
  bool operator!=(const ModInt& other) const { return val != other.val; }
  friend istream& operator>>(istream& is, ModInt& mi) { is >> mi.val; mi = ModInt(mi.val); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& mi) { return os << mi.val; }
};

using mint = ModInt<998244353>;

const int MAXN = 4e6;
mint fact[MAXN + 1];
 
void precompute() {
  fact[0] = 1;
  for(int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i;
}

void solve() {
  int a, o, b, g; cin >> a >> o >> b >> g;
  // apple, orange, banana, grape

  auto C = [&](int n, int k) {
    return fact[n] / (fact[n - k] * fact[k]);
  };

  // we only need determine the position of apples and bananas
  // because for every valid way to put the apples and bananas,
  // we can find a valid way to put grapes and oranges
  
  mint ans = 0;

  // let i => last position of apples
  for(int i = a; i <= a + o; i++) {
    // put apples in [1, i − 1]
    mint apples = C(i - 1, a - 1);

    // put bananas in [i + 1, total fruit]
    mint bananas = C(a + o + b + g - i, b);

    ans += apples * bananas;
  }

  print(ans);
}

signed main() {
  fastio;
  // #undef endl

  precompute();
  // cout << fixed << setprecision(6);
  // int t; cin >> t; while(t--)
  solve();
}