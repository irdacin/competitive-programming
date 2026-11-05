#include <bits/stdc++.h>
#include <ranges>
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

    node(int _val = 0){
      val = _val;
    }
  };

  int n;
  vec<node> tree;

  SegmentTree(int _n) : n(_n) {
    int sz = 1;
    for(; sz < n; sz <<= 1);
    tree.resize(sz << 1);
  }

  node merge(node left, node right){
    node res;
    res.val = left.val + right.val;
    return res;
  }

  void update(int l, int r, int id, int pos, int val){
    if(l == r){
      tree[id] = node(val);
      return;
    }

    if(pos <= m) update(l, m, lc, pos, val);
    else update(m + 1, r, rc, pos, val);
    tree[id] = merge(tree[lc], tree[rc]);
  }

  node query(int l, int r, int id, int pl, int pr){
    if(l > pr || r < pl) return 0;
    if(pl <= l && r <= pr){
      return tree[id];
    }

    return merge(query(l, m, lc, pl, pr), query(m + 1, r, rc, pl, pr));
  }

  void update(int pos, int val){
    update(0, n - 1, 1, pos, val);
  }

  int query(int l, int r){
    return query(0, n - 1, 1, l, r).val;
  }

  #undef m
  #undef lc
  #undef rc
};

void solve(){
  int n, m; cin >> n >> m;
  vec<int> b(n); cin >> b;

  SegmentTree seg(n + m);
  int id = n + m;
  vec<int> pos(n);
  
  for(auto i : views::reverse(b)){
    --i;
    pos[i] = --id;
    seg.update(pos[i], 1);
  }

  int ans = 0;
  for(int x; m--;){
    cin >> x;
    x--;

    seg.update(pos[x], 0);
    ans += seg.query(id, pos[x]) * 2;

    pos[x] = --id;
    seg.update(pos[x], 1);
  }

  print(ans);
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << setprecision(6) << fixed;
  // int t; cin >> t; while(t--)
  solve();
}