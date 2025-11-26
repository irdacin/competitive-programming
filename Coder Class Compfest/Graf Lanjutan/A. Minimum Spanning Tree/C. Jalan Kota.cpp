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
const int INF = 2e18;

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

struct Tree {
  vvec<pii> adj;
  int h;
  vvec<int> up, uw;
  vec<int> tin, tout;
  vec<int> depth;
  int timer;

  Tree(int n) : adj(n), tin(n), tout(n), depth(n) {
    for(h = 0; 1 << h <= n; h++);
    up.resize(n, vec<int>(h, -1));
    uw.resize(n, vec<int>(h, 0));
  }

  void add_edge(int u, int v, int w) {
    adj[u].eb(v, w);
    adj[v].eb(u, w);
  }

  void build() {
    timer = 0;
    depth[0] = 0;
    dfs(0);
  }

  void dfs(int u, int p = -1) {
    tin[u] = ++timer;

    up[u][0] = p;
    for(int i = 1; i < h && up[u][i - 1] != -1; i++) {
      up[u][i] = up[up[u][i - 1]][i - 1];
      uw[u][i] = max(uw[u][i - 1], uw[up[u][i - 1]][i - 1]);
    }

    for(auto [v, w] : adj[u]) {
      if(v == p) continue;

      depth[v] = depth[u] + 1;
      uw[v][0] = w;
      dfs(v, u);
    }

    tout[u] = ++timer;
  }

  int kth_ancestor(int u, int k) {
    for(int i = 0; k > 0 && u != -1; i++, k >>= 1) {
      if(k & 1) u = up[u][i];
    }

    return u == -1 ? -1 : u + 1;
  }

  int kth_max(int u, int k) {
    int res = 0;
    for(int i = 0; k > 0 && u != -1; i++, k >>= 1) {
      if(k & 1) res = max(res, uw[u][i]), u = up[u][i];
    }

    return res;
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
  int n, m; cin >> n >> m;
  vec<iii> edges(m);
  for(auto &[p, u, v] : edges) cin >> u >> v >> p, u--, v--;
  sort(all(edges));

  DSU dsu(n);
  Tree tree(n);

  int mst = 0;
  vec<bool> used(m);

  for(int i = 0; i < m; i++) {
    auto [p, u, v] = edges[i];
    if(dsu.unite(u, v)) {
      tree.add_edge(u, v, p);
      mst += p;
      used[i] = true;
    }
  }
  
  tree.build();

  int ans = INF;
  
  for(int i = 0; i < m; i++) {
    if(used[i]) continue;
    
    auto [p, u, v] = edges[i];
    int acs = tree.lca(u, v);

    int cost = mst + p - max(tree.kth_max(u, tree.dist(u, acs)), tree.kth_max(v, tree.dist(v, acs)));
    ans = min(ans, cost);
  }

  assert(ans != INF);
  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}