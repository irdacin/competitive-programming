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
template <typename T> inline void prinsp(T&& A, char sp = ' ') { prin(A, sp); }

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

  bool operator<(const ModInt& other) const { return val < other.val; }
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
  vec<string> s(3); cin >> s;

  vec<string> cur;
  auto func = [&](auto func, int mask) {
    if(len(cur) == 3) {
      string s1 = cur[0];
      string s2 = cur[1];
      string s3 = cur[2];

      RollingHash rh1(s1), rh2(s2), rh3(s3);
      // print(s1, s2, s3);
      int lst1 = 0;
      for(int i = len(s1) - 1, j = 0; i >= 0 && j < len(s2); i--, j++) {
        if(rh1.get(i, len(s1)) == rh2.get(0, j + 1)) lst1 = j + 1;
      }

      for(int i = 0; i + len(s1) - 1 < len(s2) && lst1 != len(s1); i++) {
        // print(i, i + len(s2));
        // if(i == 8) {
        //   print(rh1.get(0, len(s2)) , rh2.get(i, i + len(s2)));
        //   print(s2.substr(0, len(s2)), s1.substr(i, i + len(s2)));
        // }
        if(rh1.get(0, len(s1)) == rh2.get(i, i + len(s1))) lst1 = len(s1);
      }

      int lst2 = 0;
      for(int i = len(s2) - 1, j = 0; i >= 0 && j < len(s3); i--, j++) {
        if(rh2.get(i, len(s2)) == rh3.get(0, j + 1)) lst2 = j + 1;
      }

      for(int i = 0; i + len(s3) - 1 < len(s2) && lst2 != len(s3); i++) {
        if(rh3.get(0, len(s3)) == rh2.get(i, i + len(s3))) lst2 = len(s3);
      }

      // print(lst1, lst2);
      // print(len(s1) + len(s2) + len(s3));
      // print(len(s1) + len(s2) + len(s3) - lst1 - lst2);

      return len(s1) + len(s2) + len(s3) - lst1 - lst2;
    }

    int res = INF;
    for(int i = 0; i < 3; i++) {
      if(!(mask >> i & 1)) {
        cur.eb(s[i]);
        res = min(res, func(func, mask | (1 << i)));
        cur.pop_back();
      }
    }

    return res;
  };

  print(func(func, 0));
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}