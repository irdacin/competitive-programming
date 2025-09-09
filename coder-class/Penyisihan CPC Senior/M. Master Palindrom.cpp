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

template<int M>
struct ModInt {
  int val;
  ModInt(int v = 0) : val(v) { if(val < 0 || val >= M) val %= M; if(val < 0) val += M; }
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
  friend ModInt operator+(const ModInt& lhs, const ModInt& rh) { return ModInt(lhs) += rh; }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rh) { return ModInt(lhs) -= rh; }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rh) { return ModInt(lhs) *= rh; }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rh) { return ModInt(lhs) /= rh; }

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
// using mint = ModInt<998244353>;

struct RollingHash {
  using mint7 = ModInt<1000000007>;
  using mint9 = ModInt<1000000009>;
  const int BASE = 131;

  vec<mint7> hash1, power1;
  vec<mint9> hash2, power2;

  RollingHash(const string& s) {
    int n = len(s);
    hash1.resize(n + 1); hash2.resize(n + 1);
    power1.resize(n + 1); power2.resize(n + 1);
    hash1[0] = 0; hash2[0] = 0;
    power1[0] = 1; power2[0] = 1;

    for(int i = 0; i < n; i++) {
      hash1[i + 1] = hash1[i] * BASE + s[i];
      hash2[i + 1] = hash2[i] * BASE + s[i];
      power1[i + 1] = power1[i] * BASE;
      power2[i + 1] = power2[i] * BASE;
    }
  }

  pair<mint7, mint9> get(int l, int r) { // [l, r)
    mint7 h1 = hash1[r] - hash1[l] * power1[r - l];
    mint9 h2 = hash2[r] - hash2[l] * power2[r - l];
    return {h1, h2};
  }
};

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  
  RollingHash rh(s);
  int ans = 0;

  for(int i = 0, j = n - 1; i <= j; i++, j--) {
    int le = i, ri = j;
    for(; le < ri && rh.get(i, le + 1) != rh.get(ri, j + 1); le++, ri--);

    if(le < ri) ans += 2;
    else ans++;

    i = le, j = ri;
  }
  
  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}