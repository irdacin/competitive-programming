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

void solve() {
  int n, m, x, y; cin >> n >> m >> x >> y;
  map<int, set<int>> row, col;
  for(int x, y; n--;) cin >> x >> y, row[x].emp(y), col[y].emp(x);

  auto get = [&](char d) { return d == 'U' ? 0 : d == 'D' ? 1 : d == 'L' ? 2 : 3; };
  vec<pii> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

  int cnt = 0;
  for(auto [d, c] = pair<char, int>(); m--;) {
    cin >> d >> c;
    auto [nx, ny] = dir[get(d)];
    nx *= c, ny *= c;
    nx += x, ny += y;

    // print(x, y, nx, ny);

    auto r1 = row[x].lower_bound(min(y, ny));
    auto r2 = row[x].upper_bound(max(y, ny));
    auto c1 = col[y].lower_bound(min(x, nx));
    auto c2 = col[y].upper_bound(max(x, nx));

    // print(row[x], (*r1), (*r2));
    // print(col[y], (*c1), (*c2));
    for(; r1 != r2; cnt++) {
      // print("hapus r", *r1, *c1);
      col[*r1].erase(x);
      row[x].erase(r1++);
    }
    for(; c1 != c2; cnt++) {
      // print("hapus c", *r1,*c1);
      row[*c1].erase(y);
      col[y].erase(c1++);
    }
    x = nx, y = ny;
  }
  print(x, y,  cnt);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while (t--)
  solve();
}