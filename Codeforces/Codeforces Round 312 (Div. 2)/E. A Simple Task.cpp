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
    array<int, 26> freq;
    node() : freq{} {}
    node(char c) : freq{} { freq[c - 'a'] = 1; }

    friend node merge(const node& left, const node& right) {
      node res;
      for(int i = 0; i < 26; i++) res.freq[i] = left.freq[i] + right.freq[i];
      return res;
    }
  };

  struct lazy {
    int val;
    lazy() : val(-1) {}
  };

  int n, h;
  vec<node> tree;
  vec<lazy> lz;

  SegmentTree(int _n) : n(_n), h(0) {
    for(; 1 << h < n; h++);
    tree.resize(n << 1);
    lz.resize(n);
  }

  SegmentTree(const vec<char>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) tree[i + n] = node(v[i]);
    for(int id = n - 1; id; id--) pull(id);
  }

  void apply(int id, int k, int value) {
    for(int c = 0; c < 26; c++) tree[id].freq[c] = 0;
    tree[id].freq[value] = k;
    
    if(id < n) {
      lz[id].val = value;
    }
  }
  
  void push(int id, int k) {
    if(lz[id].val != -1) {
      apply(id << 1, k, lz[id].val);
      apply(id << 1 | 1, k, lz[id].val);

      lz[id].val = -1;
    }
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
      if(le & 1) apply(le++, k, value);
      if(ri & 1) apply(--ri, k, value);
    }

    for(int i = 1; i <= h; i++) {
      if(l >> i << i != l) pull(l >> i);
      if(r >> i << i != r) pull((r - 1) >> i);
    }
  }

  char query(int id) {
    // --id;
    id += n;

    for(int i = h; i; i--) push(id >> i, 1 << (i - 1));
    for(int c = 0; c < 26; c++) if(tree[id].freq[c] == 1) return c + 'a';
  }

  array<int, 26> query(int l, int r) {
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

    return merge(resL, resR).freq;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vec<char> s(n); cin >> s;

  SegmentTree seg(s);
  for(int i, j, k; q--;) {
    cin >> i >> j >> k;

    auto freq = seg.query(i, j);

    if(k) {
      for(int c = 0; c < 26; c++) {
        if(freq[c] > 0) seg.update(i, i + freq[c] - 1, c), i += freq[c];
      }
    } else {
      for(int c = 25; c >= 0; c--) {
        if(freq[c] > 0) seg.update(i, i + freq[c] - 1, c), i += freq[c];
      }
    }
  }

  for(int i = 0; i < n; i++) prin(seg.query(i));
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}