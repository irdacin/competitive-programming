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

struct SegmentTree {
  struct node {
    int val;
    node(int v = INF) : val(v) {}

    friend node merge(const node& left, const node& right) {
      node res;
      res.val = min(left.val, right.val);
      return res;
    }
  };

  int n;
  vec<node> tree;

  SegmentTree(int _n) : n(_n) {
    tree.resize(n << 1);
  }

  SegmentTree(const vec<int>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < len(v); i++) tree[i + n] = node(v[i]);
    for(int id = n - 1; id; id--) pull(id);
  }

  void pull(int id) {
    tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
  }

  void update(int id, int value) {
    --id;
    id += n;

    tree[id].val = value;
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  int query(int id) {
    --id;
    id += n;

    return tree[id].val;
  }

  int query(int l, int r) {
    --l, --r;
    
    node resL, resR;
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
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
  for(string s; q--;) {
    cin >> s;

    vec<int> v;
    for(int num = 0, i = 6; i < len(s); i++) {
      if(s[i] >= '0' && s[i] <= '9') num = num * 10 + (s[i] - '0');
      else v.eb(num), num = 0;
    }

    if(s[0] == 's') {
      int tmp = seg.query(v[0]);
      for(int i = 0; i < len(v) - 1; i++) {
        seg.update(v[i], seg.query(v[i + 1]));
      }
      seg.update(v.back(), tmp);
      
    } else print(seg.query(v[0], v[1]));
    
  }
}
 
signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}