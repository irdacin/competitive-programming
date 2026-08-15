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

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;
const double EPS = 1e-9;

void solve(int n) {
  int sx, sy, dx, dy; cin >> sx >> sy >> dx >> dy, sx--, sy--, dx--, dy--;
  vvec<bool> obs(n * 2, n * 2);
  for(int x, y; cin >> x >> y && x && y;) obs[--x][--y] = true;

  vvvec<int> dist(n * 2, n * 2, 3, INF);
  queue<iii> q;
  for(int t = 0; t < 3; t++) q.emp(sx, sy, t), dist[sx][sy][t] = 0;

  while(!q.empty()) {
    auto [r, c, t] = q.front(); q.pop();
    if(r == dx && c == dy) return print("Result", ":", dist[r][c][t]);

    vvec<pii> dir = {
      {{r - 2, c - 1}, {r - 1, c - 2}, {r - 2, c + 1}, {r + 1, c - 2}, {r + 2, c - 1}, {r - 1, c + 2}, {r + 1, c + 2}, {r + 2, c + 1}},
      {{r - 2, c - 2}, {r - 2, c + 2}, {r + 2, c - 2}, {r + 2, c + 2}},
      {{n * 2 - 1 - r, c}, {r, n * 2 - 1 - c}},
    };

    for(int nt = 0; nt < 3; nt++) {
      if(t == nt) continue;
      for(auto [nr, nc] : dir[nt]) {
        if(nr >= 0 && nr < n * 2 && nc >= 0 && nc < n * 2 && !obs[nr][nc] && chmin(dist[nr][nc][nt], dist[r][c][t] + 1)) q.emp(nr, nc, nt);
      }
    }
  }
  
  print("Solution doesn't exist");
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while (t--)
  for(int n; cin >> n && n;)
  solve(n);
}