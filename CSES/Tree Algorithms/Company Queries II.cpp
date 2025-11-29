#include <bits/stdc++.h>
using namespace std;

// #define int long long
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
const double EPS = 1e-9;

struct Tree {
  vvec<int> adj;
  int h;
  vvec<int> up;
  vec<int> tin, tout;
  vec<int> depth;
  int timer;

  Tree(int n) : adj(n), tin(n), tout(n), depth(n) {
    for(h = 0; 1 << h <= n; h++);
    up.resize(n, vec<int>(h, -1));
  }

  void add_edge(int u, int v) {
    adj[u].eb(v);
    adj[v].eb(u);
  }

  void build() {
    timer = -1;
    depth[0] = 0;
    dfs(0);
  }

  void dfs(int u, int p = -1) {
    tin[u] = ++timer;

    up[u][0] = p;
    for(int i = 1; i < h && up[u][i - 1] != -1; i++) {
      up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for(auto v : adj[u]) {
      if(v == p) continue;

      depth[v] = depth[u] + 1;
      dfs(v, u);
    }

    tout[u] = timer;
  }

  int kth_ancestor(int u, int k) {
    for(int i = 0; k > 0 && u != -1; i++, k >>= 1) {
      if(k & 1) u = up[u][i];
    }

    return u == -1 ? -1 : u + 1;
  }

  bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
  }

  int lca(int u, int v) {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for(int i = h - 1; i >= 0; i--) {
      if(up[u][i] != -1 && !is_ancestor(up[u][i], v))
        u = up[u][i];
    }

    return up[u][0];
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
};

void solve() {
  int n, q; cin >> n >> q;

  Tree tree(n);
  for(int i = 1, e; i < n; i++) cin >> e, tree.add_edge(--e, i);
  tree.build();

  for(int u, v; q--;) {
    cin >> u >> v;
    print(tree.lca(--u, --v) + 1);
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}