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

void solve() {
  int n, m; cin >> n >> m;
  vvec<int> grid(n, m); cin >> grid;
  int a, b, c, d; cin >> a >> b >> c >> d;
  a--, b--, c--, d--;

  vec<pii> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vvec<int> dist(n, m, INF);
  priority_queue<iii, vec<iii>, greater<iii>> pq;
  pq.emplace(0, a, b);
  dist[a][b] = 0;

  while(!pq.empty()) {
    auto [dist_rc, row, col] = pq.top(); pq.pop();

    if(row == c && col == d) return print(dist[row][col]);
    if(dist_rc > dist[row][col]) continue;

    for(auto [x, y] : dir) {
      x += row, y += col;
      if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != -1 && dist[x][y] > max(grid[x][y], dist[row][col])) {
        dist[x][y] = max(grid[x][y], dist[row][col]);
        pq.emplace(dist[x][y], x, y);
      }
    }
  }

  print(dist[c][d]);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}