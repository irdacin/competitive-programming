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

template <int M>
struct ModInt {
  int32_t val;
  ModInt(int v = 0) { if(v < 0 || v >= M) v %= M; if(v < 0) v += M; val = v; }
  explicit operator int() const { return val; }

  ModInt& operator+=(const ModInt& other) { return (val += other.val) >= M ? val -= M : val, *this; }
  ModInt& operator-=(const ModInt& other) { return (val -= other.val) < 0 ? val += M : val, *this; }
  ModInt& operator*=(const ModInt& other) { return val = 1LL * val * other.val % M, *this; }
  ModInt& operator/=(const ModInt& other) { return *this *= inv(other.val); }
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  ModInt operator++(int32_t) { ModInt mi = *this; ++*this; return mi; }
  ModInt operator--(int32_t) { ModInt mi = *this; --*this; return mi; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt() -= *this; }
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }

  friend ModInt pow(ModInt mi, int k) { ModInt r(1); for(; k > 0; k >>= 1, mi *= mi) if(k & 1) r *= mi; return r; }
  static ModInt inv(ModInt mi) { return pow(mi, M - 2); }

  bool operator==(const ModInt& other) const { return val == other.val; }
  bool operator!=(const ModInt& other) const { return val != other.val; }
  friend istream& operator>>(istream& is, ModInt& mi) { int x; is >> x; mi = ModInt(x); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& mi) { return os << mi.val; }
};

// using mint = ModInt<1000000007>;
using mint = ModInt<998244353>;

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

  void apply(int id, tag& t, int k = 1) {
    t.apply(d[id], k);
    if(id < n) lz[id].combine(t);
  }

  void push(int id, int k) {
    apply(id << 1, lz[id], k >> 1);
    apply(id << 1 | 1, lz[id], k >> 1);
    lz[id] = tag();
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void update(int id, tag value) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    apply(id, value);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  void update(int l, int r, tag value) { // [l, r)
    l += n, r += n;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << i);
      if(r >> i << i != r) push((r - 1) >> i, 1 << i);
    }

    for(int le = l, ri = r, k = 1; le < ri; le >>= 1, ri >>= 1, k <<= 1) {
      if(le & 1) apply(le++, value, k);
      if(ri & 1) apply(--ri, value, k);
    }

    for(int i = 1; i <= h; i++) {
      if(l >> i << i != l) pull(l >> i);
      if(r >> i << i != r) pull((r - 1) >> i);
    }
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

struct node {
  int val;
  node(mint v = 0) : val(v) {}

  friend node merge(const node& left, const node& right) {
    node res;
    res.val = left.val + right.val;
    return res;
  }
};

struct tag {
  int inc, set;

  tag() : inc(0), set(-1) {}
  tag(int i, int s) : inc(i), set(s) {}

  void apply(node& t, int k) {
    if(set != -1) t.val = k * set;
    t.val += k * inc;
  }

  void combine(const tag& t) {
    if(t.set != -1) set = t.set, inc = 0;
    inc += t.inc;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vec<node> a(n);
  for(auto &x : a) cin >> x.val;

  SegmentTree<node, tag> seg(a);
  for(int t, l, r; q--;) {
    cin >> t >> l >> r; l--;
    if(int x; t == 1) cin >> x, seg.update(l, r, tag(x, -1));
    else if(t == 2) cin >> x, seg.update(l, r, tag(0, x));
    else print(seg.query(l, r).val);
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}