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
const double INF = 2e18;
const double EPS = 1e-9;

struct point {
  double x, y;
  point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  point operator+(const point& p) const { return point(x + p.x, y + p.y); }
  point operator-(const point& p) const { return point(x - p.x, y - p.y); }

  double dot(const point& p) const { return x * p.x + y * p.y; }
  double cross(const point& p) const { return x * p.y - y * p.x; }
  double dot(const point& p, const point& q) const { return (p - *this).dot(q - *this); }
  double cross(const point& p, const point& q) const { return (p - *this).cross(q - *this); }
  double dist2(const point& p) const { return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y); }
  double dist(const point& p) const { return sqrt(dist2(p)); }

  friend bool intersect(point p, point q, point r, point s) {
    auto sign = [](int x) { return x >= 0 ? x > 0 : -1; };
    auto overlap = [](int a, int b, int c, int d) {
      return max(min(a, b), min(c, d)) <= min(max(a, b), max(c, d));
    };

    if(sign(p.cross(r, s)) == 0 && sign(r.cross(p, q)) == 0)
      return overlap(p.x, q.x, r.x, s.x) && overlap(p.y, q.y, r.y, s.y);

    return sign(p.cross(r, s)) != sign(q.cross(r, s)) && sign(r.cross(p, q)) != sign(s.cross(p, q));
  }

  bool operator==(const point& p) const { return x == p.x && y == p.y; }
  bool operator!=(const point& p) const { return x != p.x || y != p.y; }
  bool operator<(const point& p) const { return x < p.x || x == p.x && y < p.y; }
  bool operator>(const point& p) const { return x > p.x || x == p.x && y > p.y; }
  friend istream& operator>>(istream& is, point& p) { return is >> p.x >> p.y; }
  friend ostream& operator<<(ostream& os, const point& p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

void solve(int n) {
  vec<point> v(n); cin >> v;
  sort(all(v));

  // https://www.geeksforgeeks.org/dsa/closest-pair-of-points-using-divide-and-conquer-algorithm/

  auto dnc = [&](auto dnc, int l, int r) {
    if(l == r) return INF;

    int m = (l + r) / 2;
    double res = min(dnc(dnc, l, m), dnc(dnc, m + 1, r));

    vec<point> strip;
    for(int i = l; i <= r; i++) {
      if((v[i] - v[m]).x < res) strip.eb(v[i]);
    }
    sort(all(strip), [&](auto a, auto b) { return a.y < b.y; });

    for(int i = 0; i < len(strip); i++) {
      for(int j = i + 1; j < len(strip); j++) {
        if((strip[j] - strip[i]).y >= res) break;
        chmin(res, strip[i].dist(strip[j]));
      }
    }

    return res;
  };  

  double ans = dnc(dnc, 0, n - 1);
  if(ans >= 10000) return print("INFINITY");
  print(ans);
}

signed main() {
  fastio;
  cout << fixed << setprecision(4);

  // precompute();
  // int t; cin >> t; while (t--)
  for(int n; cin >> n && n;)
  solve(n);
}