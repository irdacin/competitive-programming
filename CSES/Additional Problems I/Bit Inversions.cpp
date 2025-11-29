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

template <class node, class tag>
struct SegmentTree {
  int n, h;
  vec<node> d;
  vec<tag> lz;

  SegmentTree(int _n) : n(_n), h(0) {
    for(; 1 << h < n; h++);
    d.resize(n << 1);
    lz.resize(n);
  }

  SegmentTree(const vec<node>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) d[i + n] = node(v[i]);
    build();
  }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void apply(int id, const tag& t, int k = 1) {
    t.apply(d[id], k);
    if(id < n) lz[id].combine(t);
  }

  void push(int id, int k) {
    if(lz[id].empty()) return;
    apply(id << 1, lz[id], k >> 1);
    apply(id << 1 | 1, lz[id], k >> 1);
    lz[id] = tag();
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void update(int id, tag t) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    apply(id, t);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  void update(int l, int r, tag t) { // [l, r)
    l += n, r += n;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << i);
      if(r >> i << i != r) push((r - 1) >> i, 1 << i);
    }

    for(int le = l, ri = r, k = 1; le < ri; le >>= 1, ri >>= 1, k <<= 1) {
      if(le & 1) apply(le++, t, k);
      if(ri & 1) apply(--ri, t, k);
    }

    for(int i = 1; i <= h; i++) {
      if(l >> i << i != l) pull(l >> i);
      if(r >> i << i != r) pull((r - 1) >> i);
    }
  }

  node all_query() { // [0, n)
    return d[1];
  } 

  node query(int id) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    return d[id];
  }

  node query(int l, int r) { // [l, r)
    l += n, r += n;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << i);
      if(r >> i << i != r) push((r - 1) >> i, 1 << i);
    }

    node resL, resR;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, d[l++]);
      if(r & 1) resR = merge(d[--r], resR);
    }

    return merge(resL, resR);
  }
};

struct Tree {
  vvec<int> adj;
  vec<int> tin, sz, par, depth, head;
  int timer;

  const bool VALUES_ON_EDGES = false;

  Tree(int n)
    : adj(n), tin(n), sz(n), par(n), depth(n), head(n)
  {}

  void add_edge(int u, int v) {
    adj[u].eb(v);
    adj[v].eb(u);
  }

  void build(int root = 0) {
    par[root] = -1;
    depth[root] = 0;
    timer = -1;
    head[root] = root;
    dfs_sz(root);
    dfs_hld(root);
  }

  void dfs_sz(int u) {
    sz[u] = 1;

    for (auto& v : adj[u]) {
      if (v == par[u]) continue;
      par[v] = u;
      depth[v] = depth[u] + 1;
      dfs_sz(v);

      sz[u] += sz[v];
      if (sz[v] > sz[adj[u][0]])
        swap(v, adj[u][0]);
    }
  }

  void dfs_hld(int u) {
    tin[u] = ++timer;

    for (auto v : adj[u]) {
      if (v == par[u]) continue;
      head[v] = v == adj[u][0] ? head[u] : v;
      dfs_hld(v);
    }
  }

  int lca(int u, int v) {
    for (; head[u] != head[v]; u = par[head[u]]) {
      if (depth[head[u]] < depth[head[v]]) swap(u, v);
    }

    return depth[u] < depth[v] ? u : v;
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }

  template <class F>
  void process(int u, F&& op) {
    op(tin[u]);
  }

  template <class F>
  void process_subtree(int u, F&& op) {
    op(tin[u] + VALUES_ON_EDGES, tin[u] + sz[u]);
  }

  template <class F>
  auto process_path(int u, int v, F&& op) -> decltype(void(op(0, 0))) {
    for(; head[u] != head[v]; u = par[head[u]]) {
      if(depth[head[u]] < depth[head[v]]) swap(u, v);
      op(tin[head[u]], tin[u] + 1);
    }

    if(depth[u] > depth[v]) swap(u, v);
    op(tin[u] + VALUES_ON_EDGES, tin[v] + 1);
  }

  template <class F>
  auto process_path(int u, int v, F&& op) -> decltype(void(op(0, 0, false))) {
    for(int l = lca(u, v), i = 2; i--; swap(u, v)) {
      for(; head[u] != head[l]; u = par[head[u]]) {
        op(tin[head[u]], tin[u] + 1, i);
      }
    }

    if(depth[u] > depth[v]) op(tin[v] + VALUES_ON_EDGES, tin[u] + 1, 1);
    else op(tin[u] + VALUES_ON_EDGES, tin[v] + 1, 0);
  }
};

struct node {
  int pref[2], suff[2], ans[2];
  int sz;
  node() {
    pref[0] = pref[1] = -1;
    suff[0] = suff[1] = -1;
    ans[0] = ans[1] = -1;
    sz = 0;
  }

  node(char v) {
    pref[0] = suff[0] = ans[0] = v == '0';
    pref[1] = suff[1] = ans[1] = v == '1';
    sz = 1;
  }

  int maxLength() {
    return max(ans[0], ans[1]);
  }

  friend node reverse(node x) {
    return x;
  }

  friend node merge(const node& left, const node& right) {
    if(left.ans[0] == -1) return right;
    if(right.ans[0] == -1) return left;
    node res;
    for(int i = 0; i < 2; i++) {
      res.pref[i] = left.pref[i] == left.sz ? left.pref[i] + right.pref[i] : left.pref[i];
      res.suff[i] = right.suff[i] == right.sz ? right.suff[i] + left.suff[i] : right.suff[i];
      res.ans[i] = max({left.ans[i], right.ans[i], left.suff[i] + right.pref[i]});
    }
    res.sz = left.sz + right.sz;
    return res;
  }
};

struct tag {
  bool flip;
  tag() : flip(0) {}
  tag(int f) : flip(f) {}

  bool empty() const {
    return !flip;
  }

  void apply(node& x, int k) const {
    if(flip) {
      // debug(x.ans);

      // debug(k);
      swap(x.pref[0], x.pref[1]);
      swap(x.suff[0], x.suff[1]);
      swap(x.ans[0], x.ans[1]);
      // for(int i = 0; i < 2; i++) {
      //   x.pref[i] = k - x.pref[i];
      //   x.suff[i] = k - x.suff[i];
      //   x.ans[i] = k - x.ans[i];
      // }
    }
  }

  void combine(const tag& t) {
    flip ^= t.flip;
  }
};

/*
void solve() {
  int n, q; cin >> n >> q;
  vec<int> a(n); cin >> a;

  Tree tree(n);
  for(int i = 1, u, v; i < n; i++) cin >> u >> v, u--, v--, tree.add_edge(u, v);
  tree.build();

  SegmentTree<node, tag> seg(n);
  for(int i = 0; i < n; i++) tree.process(i, [&](int id) { seg.d[id + n] = node(a[i]); });
  seg.build();

  for(int t, u, v; q--;) {
    cin >> t >> u >> v; u--, v--;
    if(t == 1) {
      tree.process_path(u, v, [&](int l, int r) {
        seg.update(l, r, tag(true));
      });
    } else {
      node resL, resR;
      tree.process_path(u, v, [&](int l, int r, bool rev) {
        print(l, r - 1, rev);
        if(rev) resL = merge(resL, reverse(seg.query(l, r)));
        else resR = merge(seg.query(l, r), resR);
      });

      node res = merge(resL, resR);
    }
  }
}
*/

void solve() {
  string s; cin >> s;

  SegmentTree<node, tag> seg(len(s));
  for(int i = 0; i < len(s); i++) seg.d[i + len(s)] = node(s[i]);
  seg.build();

  int q; cin >> q;
  for(int x; q--;) {
    cin >> x, x--;
    seg.update(x, x + 1, tag(true));
    // seg.update(x, tag(true));
    // print(seg.all_query().maxLength());
    print(seg.query(0, len(s)).maxLength());
    // print(seg.query(x).ans[0]);
    // print(seg.query(x).ans[1]);
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}