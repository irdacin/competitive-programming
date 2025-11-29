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
void println(auto &&...args) { print(args...), cout << endl; }

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

struct point {
  using T = double;
  T x, y;
  point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
  point operator+(const point& p) const { return point(x + p.x, y + p.y); }
  point operator-(const point& p) const { return point(x - p.x, y - p.y); }
  
  T dot(const point& p) const { return x * p.x + y * p.y; }
  T cross(const point& p) const { return x * p.y - y * p.x; }
  T dot(const point& p, const point& q) const { return (p - *this).dot(q - *this); }
  T cross(const point& p, const point& q) const { return (p - *this).cross(q - *this); }
  double dist(const point& p) const { return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); }

  friend bool intersect(point p, point q, point r, point s) {
    auto sign = [](T x) { return x >= 0 ? x > 0 : -1; };
    auto overlap = [](T a, T b, T c, T d) {
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


struct line {
  double a, b, c;
  // ax + by = c

  line() {}
  line(point p, point q) {
    auto [y, x] = q - p;
    a = x;
    b = -y;
    c = p.x * x - p.y * y;
    print(a, b, c);
  }

  friend point intersect(line pq, line rs) {
    if(abs((pq.a * rs.b - rs.a * pq.b)) < EPS) return {-1, -1};

    double x = (pq.c * rs.b - rs.c * pq.b) / (pq.a * rs.b - rs.a * pq.b);
    double y = (pq.c * rs.a - rs.c * pq.a) / (pq.b * rs.a - rs.b * pq.a);
    return {x, y};
  }
};

void solve() {
  point p, q, r, s; cin >> p >> q >> r >> s;

  print(intersect(p, q, r, s) ? "YES" : "NO");
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  int t; cin >> t; while(t--)
  solve();
}