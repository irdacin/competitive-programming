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
  for(auto &_i : _v) { os << _i; if (&_i != &_v.back()) os << ' '; } return os;
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

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e18;

struct point {
  int x, y;
  point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  point operator+(const point& p) const { return point(x + p.x, y + p.y); }
  point operator-(const point& p) const { return point(x - p.x, y - p.y); }
  
  int cross(const point& p) const { return x * p.y - y * p.x; }
  int cross(const point& p, const point& q) const { return (p - *this).cross(q - *this); }
  double dist(const point& p) const { return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); }

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
  friend istream& operator>>(istream& is, point& p) { return is >> p.x >> p.y; }
  friend ostream& operator<<(ostream& os, const point& p) { return os << p.x << ' ' << p.y << endl; }
};

void solve() {
  point s, f; cin >> s >> f;

  vec<point> dots;
  vec<pair<point, point>> lines;
  dots.eb(s);
  dots.eb(f);

  int n; cin >> n;
  for(point a, b; n--;) {
    cin >> a >> b;
    lines.eb(a, b);
    dots.eb(a);
    dots.eb(b);
  }

  vvec<pair<int, double>> adj(len(dots));
  for(int u = 0; u < len(dots); u++) {
    for(int v = u + 1; v < len(dots); v++) {
      point p = dots[u];
      point q = dots[v];

      bool hit = [&]() {
        for(auto [r, s] : lines) {
          if(p == r && q == s) return true;
          if(p != r && p != s && q != r && q != s && intersect(p, q, r, s)) return true;
        }
        return false;
      }();

      if(!hit) {
        adj[u].eb(v, p.dist(q));
        adj[v].eb(u, q.dist(p));
      }
    }
  }

  using T = pair<double, int>;
  priority_queue<T, vec<T>, greater<T>> pq;
  vec<double> dist(len(dots), INF);
  dist[0] = 0;
  pq.emplace(0, 0);

  while(!pq.empty()) {
    auto [dist_u, u] = pq.top(); pq.pop();
    if(dots[u] == f) return print(dist[u]);
    if(dist_u > dist[u]) continue;

    for(auto [v, w] : adj[u]) {
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.emplace(dist[v], v);
      }
    }
  }
}

signed main() {
  fastio;
  // #undef endl

  // precompute();
  cout << fixed << setprecision(2);
  // int t; cin >> t; while(t--)
  solve();
}