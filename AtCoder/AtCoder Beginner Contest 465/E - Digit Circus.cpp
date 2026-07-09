#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

#ifndef ONLINE_JUDGE
void _print(bool _x) { cout << (_x ? "true" : "false"); }
template <typename T> void _print(const T& _x) {
  if constexpr (ranges::range<T> && !is_convertible_v<T, string>) {
    cout << "{ "; bool _f = 0;
    for (auto _e : _x) cout << (_f ? ", " : (_f = 1, "")), _print(_e);
    cout << " }";
  }
  else if constexpr (requires(T _c) { _c.empty(); _c.pop(); }) {
    cout << "{ "; bool _f = 0;
    for (auto _c = _x; !_c.empty(); _c.pop(), _f = 1) {
      cout << (_f ? ", " : "");
      if constexpr (requires{ _c.top(); }) _print(_c.top());
      else _print(_c.front());
    } cout << " }";
  }
  else if constexpr (requires { typename tuple_size<T>::type; }) {
    cout << "("; bool _f = 0; apply([&](const auto&... _e) {
      ((cout << (_f ? ", " : ""), _print(_e), _f = 1), ...); }, _x
    ); cout << ")";
  }
  else cout << _x;
}
template <typename... T> void print(const T&... _x) {
  if constexpr (sizeof...(_x)) {
    bool _f = 0; ((cout << (_f ? " " : ""), _print(_x), _f = 1), ...);
  } cout << endl;
}
#define prind(...) cout << "[" << #__VA_ARGS__ << "] = "; print(__VA_ARGS__)
#else
#define prind(...)
inline void print() { cout << endl; }
template <typename T> inline void print(T&& A) { cout << A << endl; }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { cout << A << ' '; print(B...); }
#endif
template <typename T = const char*, typename... U>
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T> inline void prins(T&& A) { cout << A << ' '; }

template <typename T> bool chmax(T& a, const T& b) { return b > a ? (a = b, 1) : 0; }
template <typename T> bool chmin(T& a, const T& b) { return b < a ? (a = b, 1) : 0; }
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for (auto& _x : _v) { is >> _x; } return is;
}
template <typename T> inline void prinv(const T& A, string sp = " ") {
  bool _f = 0; for (const auto& _x : A) cout << (_f ? sp : "") << _x, _f = 1;
  cout << endl;
}

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
#define emp emplace
#define eb emplace_back
#define run(...) [&](){__VA_ARGS__}()
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 998244353;
const int INF = 2e9;
const double EPS = 1e-9;

void solve() {
  string n; cin >> n;

  vvvec<vvvec<int>> dp(len(n), 2, 3, vvvec<int>(2, 1 << 10, 2, -1));
  auto func = [&](auto func, int id, bool tight, int sum, bool three, int mask, bool leading) {
    if(id == len(n)) {
      if(leading) return 0LL;
      int res = (sum == 0) + three + (__builtin_popcount(mask) == 3);
      return res == 1 ? 1LL : 0LL;
    }

    int &res = dp[id][tight][sum][three][mask][leading];
    if(res != -1) return res;

    res = 0;
    for(int d = 0; d <= (tight ? n[id] - '0' : 9); d++) {
      (res += func(func, id + 1, tight && (d == (n[id] - '0')), (sum + d) % 3, three || d == 3, (leading && d == 0) ? mask : (mask | (1 << d)), leading && d == 0)) %= MOD;
    }
    return res;
  };

  print(func(func, 0, true, 0, false, 0, true));
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while (t--)
  solve();
}