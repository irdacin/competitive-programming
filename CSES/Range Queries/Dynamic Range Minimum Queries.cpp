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
  int _i = 0; os << "{ "; for (const auto& _x : _c) { os << (_i++ ? ", " : "") << _x; }
  return os << " }";
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T&& A, char sp = ' ') { prin(A, sp); }

template <typename T> using vec = vector<T>;
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
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;

struct SegmentTree {
  #define m ((l + r) >> 1)
  #define lc (id << 1)
  #define rc (lc | 1)

  struct node {
    int val;
    node(int _val = INF) : val(_val) {}

    node& operator+= (const node& other) {
      return val += other.val, *this;
    }

    friend node merge(node left, node right) {
      return min(left.val, right.val);
    }

    friend ostream& operator<<(ostream& os, const node& n) { 
      return os << n.val;
    }
  };

  int sz;
  vec<node> tree;
  
  SegmentTree(const int n) {
    sz = 1;
    for(; sz < n; sz <<= 1);
    tree.resize(sz << 1);
  }
  
  SegmentTree(const vec<int>& v) {
    sz = 1;
    for(; sz < len(v); sz <<= 1);
    tree.resize(sz << 1);
    build(v);
  }

  void build(const vec<int>& v) {
    for(int i = 0; i < sz; i++)
      tree[i + sz] = v[i];
    for(int id = sz - 1; id > 0; id--)
      tree[id] = merge(tree[lc], tree[rc]);
  }
  
  void update(int l, int r, int id, int pos, int val) {
    if(l == r) {
      tree[id] = node(val);
      return;
    }

    if(pos <= m) update(l, m, lc, pos, val);
    else update(m + 1, r, rc, pos, val);
    tree[id] = merge(tree[lc], tree[rc]);
  }

  node query(int l, int r, int id, int pl, int pr) {
    if(l > pr || r < pl) return node();
    if(pl <= l && r <= pr) {
      return tree[id];
    }

    return merge(query(l, m, lc, pl, pr), query(m + 1, r, rc, pl, pr));
  }

  void update(int pos, int val) {
    update(0, sz - 1, 1, pos - 1, val);
  }

  int query(int l, int r) {
    return query(0, sz - 1, 1, l - 1, r - 1).val;
  }

  #undef m
  #undef lc
  #undef rc
};

void solve() {
  int n, q; cin >> n >> q;
  vec<int> a(n); cin >> a;

  SegmentTree seg(a);
  for(int t, l, r; q--;) {
    cin >> t >> l >> r;
    if(t == 1) seg.update(l, r);
    else print(seg.query(l, r));
  }
}

signed main() {
  fastio;
 
  // precompute();
  // cout << fixed << setprecision(6);
  // int t; cin >> t; while(t--)
  solve();
}