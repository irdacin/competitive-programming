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

struct DSU {
  vec<int> parent, sizes;
  DSU(int n) : parent(n), sizes(n, 1) {
    iota(all(parent), 0);
  }

  int find(int u) {
    return u == parent[u] ? u : parent[u] = find(parent[u]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return false;
    
    if(sizes[u] < sizes[v]) swap(u, v);
    sizes[u] += sizes[v];
    parent[v] = u;
    return true;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vvec<int> a(n, m); cin >> a;

  map<int, vec<int>> mp;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) mp[a[i][j]].eb(i * m + j);
  }

  DSU dsu(n * m);
  vvec<bool> vis(n, m);

  int ans = 0;
  
  for(int cur = 0; auto [_, v] : mp | views::reverse) {
    
    int cnt = 0;
    for(auto x : v) {
      int i = x / m, j = x % m;
      vis[i][j] = true;

      for(auto [x, y] : vec<pii>{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}) {
        x += i, y += j;
        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y]) {
          cnt += dsu.unite(i * m + j, x * m + y);
        }
      }
    }

    cur += len(v) - cnt;
    ans = max(ans, cur);
  }

  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}