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
const double EPS = 1e-9;

struct SegmentTree {
  struct node {
    int val;
    node(int v = 0) : val(v) {}

    friend node merge(const node& left, const node& right) {
      node res;
      res.val = left.val + right.val;
      return res;
    }
  };

  int n;
  vec<node> d;

  SegmentTree(int _n) : n(_n) {
    d.resize(n << 1);
  }

  SegmentTree(const vec<int>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) d[i + n] = node(v[i]);
    build();
  }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void update(int id, int value) {
    id += n;
    d[id] = node(value);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  int query(int id) {
    return d[id += n].val;
  }

  int query(int l, int r) { // [l, r)
    node resL, resR;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, d[l++]);
      if(r & 1) resR = merge(d[--r], resR);
    }

    return merge(resL, resR).val;
  }
};

struct Tree {
  vvec<int> adj;
  vec<int> sz, tin, par, depth, head, tour;
  int timer;

  Tree(int n) : adj(n), sz(n), tin(n), par(n), depth(n), head(n), tour(n) {}

  void add_edge(int u, int v) {
    adj[u].eb(v);
    adj[v].eb(u);
  }

  void build(int root = 0) {
    par[root] = -1;
    depth[root] = 0;
    dfs_sz(root);
    timer = -1;
    head[root] = root;
    dfs_hld(root);
  }

  void dfs_sz(int u) {
    sz[u] = 1;
    for(auto &v : adj[u]) {
      if(v == par[u]) continue;
      par[v] = u;
      depth[v] = depth[u] + 1;
      dfs_sz(v);

      sz[u] += sz[v];
      if(sz[v] > sz[adj[u][0]])
        swap(v, adj[u][0]);
    }
  }

  void dfs_hld(int u) {
    tin[u] = ++timer;
    tour[timer] = u;

    for(auto &v : adj[u]) {
      if(v == par[u]) continue;
      head[v] = v == adj[u][0] ? head[u] : v;
      dfs_hld(v);
    }
  }

  int kth_ancestor(int u, int k) {
    for(;; u = par[head[u]]) {
      int v = head[u];
      if(depth[v] + k <= depth[u]) return tour[tin[u] - k];
      k -= depth[u] - depth[v] + 1;
    }
  }

  int lca(int u, int v) {
    for(; head[u] != head[v]; u = par[head[u]]) {
      if(depth[head[u]] < depth[head[v]]) swap(u, v);
    }

    return depth[u] < depth[v] ? u : v;
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }

  template <class F>
  void process_subtree(int u, F op) {
    op(tin[u], tin[u] + sz[u]);
  }

  template <class F>
  void process(int u, F op) {
    op(tin[u]);
  }

  template <class F>
  void process_path(int u, int v, F op) {
    for(; head[u] != head[v]; u = par[head[u]]) {
      if(depth[head[u]] < depth[head[v]]) swap(u, v);
      op(tin[head[u]], tin[u]);
    }

    if(depth[u] > depth[v]) swap(u, v);
    op(tin[u], tin[v]);
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vec<int> a(n); cin >> a;

  Tree tree(n);
  for(int i = 1, u, v; i < n; i++) cin >> u >> v, u--, v--, tree.add_edge(u, v);
  tree.build();

  SegmentTree seg(n);
  for(int i = 0; i < n; i++) tree.process(i, [&](int id) { seg.d[id += n] = a[i]; });
  seg.build();

  for(int t; q--;) {
    cin >> t;
    if(int s, x; t == 1) {
      cin >> s >> x; s--;
      tree.process(s, [&](int id) { seg.update(id, x); });
    } else {
      cin >> s; s--;
      int ans = 0;
      tree.process_subtree(s, [&](int l, int r) { ans += seg.query(l, r); });
      print(ans);
    }
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}