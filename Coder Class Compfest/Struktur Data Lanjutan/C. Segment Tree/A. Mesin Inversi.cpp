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
    int cnt[31];
    node() : val(0), cnt{} {}
    node(int v) : val(v) {
      for(int i = 0; i <= 30; i++) cnt[i] = val >> i & 1;
    }
    
    friend node merge(const node& left, const node& right) {
      node res;
      res.val = left.val + right.val;
      for(int i = 0; i <= 30; i++) res.cnt[i] = left.cnt[i] + right.cnt[i];
      return res;
    }
  };
  
  struct tag {
    int val;
    
    tag() : val(0) {}
    tag(int v) : val(1 << v) {}
  };

  int n, h;
  vec<node> tree;
  vec<tag> lazy;

  SegmentTree(int _n) : n(_n), h(0) {
    for(; 1 << h < n; h++);
    tree.resize(n << 1);
    lazy.resize(n);
  }

  SegmentTree(const vec<int>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) tree[i + n] = node(v[i]);
    for(int id = n - 1; id; id--) pull(id);
  }

  void apply(int id, int k, tag t) {
    if(t.val != 0) {
      for(int b = 0; b <= 30; b++) {
        if(t.val >> b & 1) {
          tree[id].val -= tree[id].cnt[b] * (1LL << b);
          tree[id].cnt[b] = k - tree[id].cnt[b];
          tree[id].val += tree[id].cnt[b] * (1LL << b);
        }
      }

      if(id < n) lazy[id].val ^= t.val;
    }
  }

  void push(int id, int k) {
    apply(id << 1, k, lazy[id]);
    apply(id << 1 | 1, k, lazy[id]);
    lazy[id] = tag();
  }

  void pull(int id) {
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
  }

  void update(int l, int r, int value) {
    --l, --r;
    l += n, r += n + 1;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << (i - 1));
      if(r >> i << i != r) push((r - 1) >> i, 1 << (i - 1));
    }

    for(int le = l, ri = r, k = 1; le < ri; le >>= 1, ri >>= 1, k <<= 1) {
      if(le & 1) apply(le++, k, tag(value));
      if(ri & 1) apply(--ri, k, tag(value));
    }

    for(int i = 1; i <= h; i++) {
      if(l >> i << i != l) pull(l >> i);
      if(r >> i << i != r) pull((r - 1) >> i);
    }
  }

  int query(int id) {
    // --id;
    id += n;

    for(int i = h; i; i--) push(id >> i, 1 << (i - 1));
    return tree[id].val;
  }

  int query(int l, int r) {
    --l, --r;
    l += n, r += n + 1;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << (i - 1));
      if(r >> i << i != r) push((r - 1) >> i, 1 << (i - 1));
    }

    node resL, resR;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, tree[l++]);
      if(r & 1) resR = merge(tree[--r], resR);
    }

    return merge(resL, resR).val;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vec<int> a(n); cin >> a;

  SegmentTree seg(a);
  for(int t, l, r; q--;) {
    cin >> t >> l >> r;
    if(int b; t == 1) cin >> b, seg.update(l, r, b);
    else print(seg.query(l, r));
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}