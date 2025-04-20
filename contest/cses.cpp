#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << x << endl

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& _v) {
  for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T &&A = "", U &&...B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T &&A, U &&...B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T &&A, const char* sp = " ") { prin(A, sp); }

template <typename T> struct vec : vector<T> { using vector<T>::vector; };
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
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7;
const int INF = 2e9;
const int MAXN = 2e5;

struct SegmentTree {
  #define m ((l + r) >> 1)
  #define lc (id << 1)
  #define rc (lc | 1)

  struct node {
    int val;
    node(int _val = 0) : val(_val) {}
    node &operator+=(int other){ return val += other, *this; }
  };

  int n;
  vec<int> v;
  vec<node> tree;
  vec<int> lazy;
  
  SegmentTree(vec<int> _v) : n(len(_v)), v(_v) {
    int sz = 1;
    for(; sz < n; sz <<= 1);
    tree.resize(sz << 1);
    lazy.resize(sz << 1);
    build(0, n - 1, 1);
  }

  node merge(node left, node right){
    return left.val + right.val;
  }

  void build(int l, int r, int id){
    if(l == r){
      tree[id] = node(v[l]);
      return;
    }

    build(l, m, lc);
    build(m + 1, r, rc);
    tree[id] = merge(tree[lc], tree[rc]);
  }

  void propagate(int l, int r, int id){
    if(lazy[id]){
      tree[id] += (r - l + 1) * lazy[id];
      if(l < r){
        lazy[lc] += lazy[id];
        lazy[rc] += lazy[id];
      }

      lazy[id] = 0;
    }
  }

  void update(int l, int r, int id, int pl, int pr, int val){
    propagate(l, r, id);

    if(l > pr || r < pl) return;
    if(pl <= l && r <= pr){
      lazy[id] = val;
      propagate(l, r, id);
      return;
    }

    update(l, m, lc, pl, pr, val);
    update(m + 1, r, rc, pl, pr, val);
    tree[id] = merge(tree[lc], tree[rc]);
  }

  node query(int l, int r, int id, int pos){
    propagate(l, r, id);

    if(l == r){
      return tree[id];
    }

    if(pos <= m) return query(l, m, lc, pos);
    else return query(m + 1, r, rc, pos);
  }

  void update(int l, int r, int val){
    update(0, n - 1, 1, l - 1, r - 1, val);
  }

  int query(int pos){
    return query(0, n - 1, 1, pos - 1).val;
  }

  #undef m
  #undef lc
  #undef rc
};

void solve(){
  int n, q; cin >> n >> q;
  vec<int> a(n); cin >> a;

  SegmentTree seg(a);
  for(int t, l, r; q--;){
    cin >> t;
    if(int l, r, k; t == 1) cin >> l >> r >> k, seg.update(l, r, k);
    else cin >> k, print(seg.query(k));
  }
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << setprecision(6) << fixed;
  // int t; cin >> t; while(t--)
  solve();
}