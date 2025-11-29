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

struct node {
  int val;
  node(int v = 0) : val(v) {}

  friend node merge(const node& left, const node& right) {
    node res;
    res.val = max(left.val, right.val);
    return res;
  }
};

struct SegmentTree {
  int n;
  vec<node> tree;

  SegmentTree(int _n) : n(_n) {
    tree.resize(n << 1);
  }

  SegmentTree(const vec<int>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) tree[i + n] = node(v[i]);
    for(int id = n - 1; id; id--) pull(id);
  }

  void pull(int id) {
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
  }

  void update(int id, node value) {
    id += n;

    tree[id] = value;
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  node query(int id) {
    id += n;

    return tree[id];
  }

  node query(int l, int r) {
    node resL, resR;
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, tree[l++]);
      if(r & 1) resR = merge(tree[--r], resR);
    }

    return merge(resL, resR);
  }
};

struct Tree {
  vvec<int> adj;
  vec<int> sz, pos, par, depth, head;
  int timer;
  SegmentTree seg;

  Tree(int n) : adj(n), sz(n), pos(n), par(n), depth(n), head(n), seg(n) {}

  void add_edge(int u, int v) {
    adj[u].eb(v);
    adj[v].eb(u);
  }

  void build(int root = 0) {
    depth[root] = 0;
    par[root] = -1;
    dfs_sz(root);
    timer = 0;
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
    pos[u] = timer++;
    
    for(auto v : adj[u]) {
      if(v == par[u]) continue;

      head[v] = v == adj[u][0] ? head[u] : v;
      dfs_hld(v);
    }
  } 

  int lca(int u, int v) {
    for(; head[u] != head[v]; u = par[head[u]]) {
      if(depth[head[u]] < depth[head[v]]) swap(u, v);
    }
    return depth[u] < depth[v] ? u : v;
  }

  template <class F>
  void process_path(int u, int v, F op) {
    for(; head[u] != head[v]; u = par[head[u]]) {
      if(depth[head[u]] < depth[head[v]]) swap(u, v);
      op(pos[head[u]], pos[u]);
    }

    if(depth[u] > depth[v]) swap(u, v);
    op(pos[u], pos[v]);
  }

  void update(int u, int val) {
    seg.update(pos[u], node(val));
  }

  // void update(int u, int v, int val) {
  //   process_path(u, v, [this, &val](int l, int r) { seg.update(l, r, val); });
  // }
  
  node query(int u, int v) {
    node res;
    process_path(u, v, [&](int l, int r) { res = merge(res, seg.query(l, r)); });
    return res;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vec<int> a(n); cin >> a;

  Tree tree(n);
  for(int i = 1, u, v; i < n; i++) cin >> u >> v, u--, v--, tree.add_edge(u, v);

  tree.build();
  for(int i = 0; i < n; i++) tree.update(i, a[i]);

  for(int t, a, b; q--;) {
    cin >> t >> a >> b;
    
    if(t == 1) tree.update(--a, b);
    else print(tree.query(--a, --b).val);
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}