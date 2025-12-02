#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

#ifndef ONLINE_JUDGE
void _print(const auto& _x);
void _print(bool _x) { cout << (_x ? "true" : "false"); }
template <typename... T> void _print(const tuple<T...>& _t) {
  cout << "("; bool _f = 0; apply([&](auto const&... _x) {
    ((cout << (_f ? ", " : ""), _print(_x), _f = 1), ...); }, _t
  ); cout << ")";
}
template <typename T, typename U> void _print(const pair<T, U>& _p) {
  cout << "("; _print(_p.first); cout << ", "; _print(_p.second); cout << ")";
}
void _print(const auto& _c) {
  if constexpr (is_same_v<decay_t<decltype(_c)>, string>) cout << _c;
  else if constexpr (requires{ _c.begin(); _c.end(); }) {
    cout << "{ "; bool _f = 0;
    for (auto _x : _c) cout << (_f ? ", " : (_f = 1, "")), _print(_x);
    cout << " }";
  }
  else if constexpr (requires{ _c.empty(); }) {
    cout << "{ "; bool _f = 0;
    for (auto _u = _c; !_u.empty(); _u.pop(), _f = 1) {
      cout << (_f ? ", " : "");
      if constexpr (requires{ _c.top(); }) _print(_u.top());
      else _print(_u.front());
    }
    cout << " }";
  }
  else cout << _c;
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
template <typename T> inline void prinv(const T& A, string sp = " ") {
  bool _f = 0; for (const auto& _x : A) cout << (_f ? sp : "") << _x, _f = 1;
  cout << endl;
}

template <typename T> using vec = vector<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for (auto& _x : _v) { is >> _x; } return is;
}
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

void solve() {
  int n; string s;
  cin >> n >> s;
  int ans = 0;
  for(int i = n - 2; i >= 0; i--) {
    if(s[i] != s[i + 1]) ans++, s[i] = s[i + 1];
  }
  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  int t; cin >> t; while (t--)
  solve();
}