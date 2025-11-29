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
 
  static u128 reduce(auto _x) {
    u128 x = _x < 0 ? ~_x + u128(1) : _x;
    
    u128 b = x * (mu >> 64);
    u128 c = mu * (x >> 64);
    u128 d = (x >> 64) * (mu >> 64);
    u128 q = d + (b >> 64) + (c >> 64);
    if(x < 0) q = ~q;
    u128 r = x - q * mod;
    if(r >= mod) r -= mod;
    return r;
  }
};
 
template<auto M>
struct ModInt {
  int val;
  ModInt(int _val = 0) : val(_val % M) { if(val >= M) val -= M; }
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
 
using mint = ModInt<Barrett{}>;
 
struct matrix : vvec<mint> {
	using vvec<mint>::vvec;
 
	matrix& operator*=(const matrix& other) {
		int n = len((*this));
		int m = len((*this)[0]);
		assert(m == len(other));
 
		matrix res(n, m);
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
	int n; cin >> n;
	Barrett::set_mod(MOD);
	matrix base = {
		{1, 1, 2, 4, 8, 16}
	};
 
	matrix trans = {
		{0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{0, 1, 0, 0, 0, 1},
		{0, 0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0, 1},
		{0, 0, 0, 0, 1, 1},
	};
 
	print((base * pow(trans, n))[0][0]);
}
 
signed main() {
	fastio;
	// #undef endl
 
	// precompute();
	// cout << fixed << setprecision(6);
	// int t; cin >> t; while(t--)
	solve();
}