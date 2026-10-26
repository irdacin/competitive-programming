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
template <typename T> inline void prinsp(T&& A, char sp = ' ') { prin(A, sp); }

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

// https://codeforces.com/blog/entry/18051
struct SegmentTree {
  struct node {
    char front, back;
    node(char f = '#', char b = '#') : front(f), back(b) {}
    
    friend node merge(const node& left, const node& right) {
      node res;
      return res;
    }
  };
  
  struct tag {
    bool flip;
    char front, back;
    
    tag() : flip(false), front(' '), back(' ') {}
  };

  int n, h;
  vec<node> tree;
  vec<tag> lazy;

  SegmentTree(int _n) : n(_n), h(0) {
    for(; 1 << h < n; h++);
    tree.resize(n << 1);
    lazy.resize(n);
  }

  void apply_flip(int id) {
    swap(tree[id].front, tree[id].back);
    if(id < n) {
      lazy[id].flip ^= 1;
      swap(lazy[id].front, lazy[id].back);
    }
  }

  void apply_front(int id, char value) {
    tree[id].front = value;
    if(id < n) lazy[id].front = value;
  }

  void apply_back(int id, char value) {
    tree[id].back = value;
    if(id < n) lazy[id].back = value;
  }
  
  void push(int id) {
    if(lazy[id].flip) {
      apply_flip(id << 1);
      apply_flip(id << 1 | 1);

      lazy[id].flip = false;
    }

    if(lazy[id].front != ' ') {
      apply_front(id << 1, lazy[id].front);
      apply_front(id << 1 | 1, lazy[id].front);

      lazy[id].front = ' ';
    }

    if(lazy[id].back != ' ') {
      apply_back(id << 1, lazy[id].back);
      apply_back(id << 1 | 1, lazy[id].back);

      lazy[id].back = ' ';
    }
  }

  void pull(int id) {
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
  }

  void flip(int l, int r) {
    --l, --r;
    l += n, r += n + 1;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i);
      if(r >> i << i != r) push((r - 1) >> i);
    }

    for(int le = l, ri = r; le < ri; le >>= 1, ri >>= 1) {
      if(le & 1) apply_flip(le++);
      if(ri & 1) apply_flip(--ri);
    }

    for(int i = 1; i <= h; i++) {
      if(l >> i << i != l) pull(l >> i);
      if(r >> i << i != r) pull((r - 1) >> i);
    }
  }

  void color(int l, int r, char value) {
    --l, --r;
    l += n, r += n + 1;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i);
      if(r >> i << i != r) push((r - 1) >> i);
    }

    for(int le = l, ri = r; le < ri; le >>= 1, ri >>= 1) {
      if(le & 1) apply_front(le++, value);
      if(ri & 1) apply_front(--ri, value);
    }

    for(int i = 1; i <= h; i++) {
      if(l >> i << i != l) pull(l >> i);
      if(r >> i << i != r) pull((r - 1) >> i);
    }
  }

  char queryFront(int id) {
    id += n;

    for(int i = h; i; i--) push(id >> i);
    return tree[id].front;
  }
  
  char queryBack(int id) {
    id += n;
    
    // for(int i = h; i; i--) push(id >> i);
    return tree[id].back;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  SegmentTree seg(n);
  
  for(int t, l, r; q--;) {
    cin >> t >> l >> r;
    if(char w; t == 1) cin >> w, seg.color(l, r, w);
    else seg.flip(l, r);
  }

  for(int i = 0; i < n; i++) prin(seg.queryFront(i)); print();
  for(int i = 0; i < n; i++) prin(seg.queryBack(i)); print();
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}