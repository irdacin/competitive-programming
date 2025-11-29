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

template <class node, bool PERSISTENT = false>
struct SegmentTree {
  struct vertex {
    int l, r;
    node d;

    vertex() : l(-1), r(-1) {}
  };

  int l0, r0;
  vec<vertex> pool;

  SegmentTree(int n = 10'000'000) {
    pool.reserve(n);
  }

  int new_root(int l, int r) {
    l0 = l, r0 = r;
    pool.eb();
    return len(pool) - 1;
  }

  int new_root(const vec<node>& a) {
    l0 = 0, r0 = len(a);
    auto build = [&](auto&& build, int l, int r) -> int {
      if(l == r) return -1;
      int v = new_vertex();
      if(l + 1 == r) return pool[v].d = a[l], v;

      int mid = (l + r) / 2;
      pool[v].l = build(build, l, mid);
      pool[v].r = build(build, mid, r);
      pull(v);
      return v;
    };
    return build(build, l0, r0);
  }

  int new_vertex(const vertex& v = vertex()) {
    pool.eb(v);
    return len(pool) - 1;
  }

  int clone(int v) {
    if(v == -1) return new_vertex();
    if(PERSISTENT) return new_vertex(pool[v]);
    return v;
  }

  void pull(int v) {
    pool[v].d = merge(
      pool[v].l != -1 ? pool[pool[v].l].d : node(),
      pool[v].r != -1 ? pool[pool[v].r].d : node()
    );
  }

  int update(int v, int l, int r, int pos, const node& t) {
    v = clone(v);
    if(l + 1 == r) return pool[v].d.apply(t), v;

    int mid = (l + r) / 2;
    if(pos < mid) pool[v].l = update(pool[v].l, l, mid, pos, t);
    else pool[v].r = update(pool[v].r, mid, r, pos, t);
    pull(v);
    return v;
  };
  
  node query(int v, int l, int r, int pos) {
    if(v == -1) return node();
    if(l + 1 == r) return pool[v].d;

    int mid = (l + r) / 2;
    if(pos < mid) return query(pool[v].l, l, mid, pos);
    else return query(pool[v].r, mid, r, pos);
  }
  
  node query(int v, int l, int r, int pl, int pr) {
    if(v == -1 || l >= pr || r <= pl) return node();
    if(pl <= l && r <= pr) return pool[v].d;

    int mid = (l + r) / 2;
    return merge(query(pool[v].l, l, mid, pl, pr), query(pool[v].r, mid, r, pl, pr));
  }

  int update(int root, int pos, node t) { return update(root, l0, r0, pos, t); } // [pos]
  node query(int root, int pos) { return query(root, l0, r0, pos); } // [pos]
  node query(int root, int l, int r) { return query(root, l0, r0, l, r); } // [l, r)
};

struct node {
  int val;
  node(int v = 0) : val(v) {}

  void apply(const node& t) {
    val = t.val;
  }

  friend node merge(const node& left, const node& right) {
    node res;
    res.val = left.val + right.val;
    return res;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vec<node> a(n);
  for(auto &x : a) cin >> x.val;

  SegmentTree<node, true> seg;
  vec<int> root;
  root.eb(seg.new_root(a));

  for(int t, k; q--;) {
    cin >> t >> k; k--;
    if(int a, b; t == 1) cin >> a >> b, a--, root[k] = seg.update(root[k], a, b);
    else if(t == 2) cin >> a >> b, a--, print(seg.query(root[k], a, b).val);
    else root.eb(root[k]);
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}