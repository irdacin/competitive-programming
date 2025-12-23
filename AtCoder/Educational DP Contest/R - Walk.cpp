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

using mint = ModInt<1000000007>;
// using mint = ModInt<998244353>;

struct matrix : vvec<mint> {
  using vvec<mint>::vvec;

  matrix& operator*=(const matrix& other) {
    int n = len((*this));
    int m = len((*this)[0]);
    assert(m == len(other));

    matrix res(n, len(other[0]));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < len(other[0]); j++)
        for(int k = 0; k < m; k++)
          res[i][j] += (*this)[i][k] * other[k][j];
    return *this = res;
  }

  matrix operator*(const matrix& other) const { 
    return matrix(*this) *= other; 
  }

 friend matrix pow(matrix mat, int k) {
    int n = len(mat);
    assert(n == len(mat[0]));

    matrix res(n, n);
    for(int i = 0; i < n; i++) res[i][i] = 1;
    for(; k > 0; k /= 2, mat *= mat) if(k & 1) res *= mat;
    return res;
  }
};

void solve() {
  int n, k; cin >> n >> k;
  matrix a(n, n); cin >> a;

  /*
  vvec<int> dp(n, k + 1, 0);
  for(int i = 0; i < n; i++) dp[i][0] = 1;

  for(int i = 1; i <= k; i++) {
    for(int row = 0; row < n; row++) {
      for(int col = 0; col < n; col++) {
        if(a[row][col] == 1) {
          dp[row][i] += dp[col][i - 1];
        }
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) ans += dp[i][k];
  print(ans);
  */

  matrix base(1, n);
  for(int i = 0; i < n; i++) base[0][i] = 1;

  matrix res = base * pow(a, k);
  mint ans = 0;
  for(int i = 0; i < n; i++) ans += res[0][i];
  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}