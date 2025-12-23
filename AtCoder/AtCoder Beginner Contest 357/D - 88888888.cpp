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
inline void prin(T &&A = "", U &&...B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T &&A, U &&...B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T &&A, const char* sp = " ") { prin(A, sp); }

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

const int MOD = 998244353;
const int INF = 2e9;

template<int M>
struct ModInt {
  int val;
  ModInt(int _val = 0) : val(_val % M) { if(val < 0) val += M; }
  
  ModInt &operator+=(const ModInt& mi) { return (val += mi.val) >= M ? val -= M : val, *this; }
  ModInt &operator-=(const ModInt& mi) { return (val -= mi.val) < 0 ? val += M : val, *this; }
  ModInt &operator*=(const ModInt& mi) { return (val *= mi.val) %= M, *this; }
  ModInt &operator/=(const ModInt& mi) { return (val *= inv(mi.val, M)) %= M, *this; }
  ModInt operator+(const ModInt& mi) const { return ModInt(*this) += mi; }
  ModInt operator-(const ModInt& mi) const { return ModInt(*this) -= mi; }
  ModInt operator*(const ModInt& mi) const { return ModInt(*this) *= mi; }
  ModInt operator/(const ModInt& mi) const { return ModInt(*this) /= mi; }
  ModInt operator-() const { return ModInt() -= *this; }
  ModInt &operator++() { return *this += 1; }
  ModInt &operator--() { return *this -= 1; }
  ModInt operator++(int32_t) { ModInt mi = *this; ++*this; return mi; }
  ModInt operator--(int32_t) { ModInt mi = *this; ++*this; return mi; }

  friend ModInt pow(ModInt mi, int k) { ModInt r = 1; for(; k > 0; mi *= mi, k >>= 1) if(k & 1) r *= mi; return r; }
  int inv(ModInt mi) { return pow(mi, M - 2).val; }
  int inv(int x, int m) { return x == 1 ? 1 : m - inv(m % x, x) * m / x; } // use this for divisor if M is not prime

  bool operator==(const ModInt& mi) const { return val == mi.val; }
  bool operator!=(const ModInt& mi) const { return val != mi.val; }
  bool operator>=(const ModInt& mi) const { return val >= mi.val; }
  bool operator<=(const ModInt& mi) const { return val <= mi.val; }
  bool operator>(const ModInt& mi) const { return val > mi.val; }
  bool operator<(const ModInt& mi) const { return val < mi.val; }
  friend istream& operator>>(istream& is, ModInt& mi) { is >> mi.val; mi = ModInt(mi.val); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& mi) { return os << mi.val; }
};

using mint = ModInt<MOD>;

void solve(){
  int n; cin >> n;

  int k = 0;
  for(int tmp = n; tmp > 0; tmp /= 10) k++;

  mint a = 10;
  mint r = pow(a, k);
  print(mint(n) * (pow(r, n) - 1) / (r - 1));
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << fixed << setprecision(6);
  // int t; cin >> t; while(t--)
  solve();
}