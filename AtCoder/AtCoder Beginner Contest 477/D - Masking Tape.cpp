#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'

#ifndef ONLINE_JUDGE
void _print(bool _x) { cout << (_x ? "true" : "false"); }
template <typename T> void _print(const T& _x) {
  if constexpr (ranges::range<T> && !is_convertible_v<T, string>) {
    cout << "{ "; bool _f = 0;
    for (auto _e : _x) cout << (_f ? ", " : (_f = 1, "")), _print(_e);
    cout << " }";
  }
  else if constexpr (requires(T _c) { _c.empty(); _c.pop(); }) {
    cout << "{ "; bool _f = 0;
    for (auto _c = _x; !_c.empty(); _c.pop(), _f = 1) {
      cout << (_f ? ", " : "");
      if constexpr (requires{ _c.top(); }) _print(_c.top());
      else _print(_c.front());
    } cout << " }";
  }
  else if constexpr (requires { typename tuple_size<T>::type; }) {
    cout << "("; bool _f = 0; apply([&](const auto&... _e) {
      ((cout << (_f ? ", " : ""), _print(_e), _f = 1), ...); }, _x
    ); cout << ")";
  }
  else cout << _x;
}
template <typename... T> void print(const T&... _x) {
  if constexpr (sizeof...(_x)) {
    bool _f = 0; ((cout << (_f ? " " : ""), _print(_x), _f = 1), ...);
  } cout << endl;
}
#define prind(...) cout << "[" << #__VA_ARGS__ << "] = "; print(__VA_ARGS__)
#else
#define prind(...)
inline void print() { cout << endl; }
template <typename T> inline void print(T&& A) { cout << A << endl; }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { cout << A << ' '; print(B...); }
#endif
template <typename T = const char*, typename... U>
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T> inline void prins(T&& A) { cout << A << ' '; }

template <typename T> bool chmax(T& a, const T& b) { return b > a ? (a = b, 1) : 0; }
template <typename T> bool chmin(T& a, const T& b) { return b < a ? (a = b, 1) : 0; }
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for (auto& _x : _v) { is >> _x; } return is;
}
template <typename T> inline void prinv(const T& A, string sp = " ") {
  bool _f = 0; for (const auto& _x : A) cout << (_f ? sp : "") << _x, _f = 1;
  cout << endl;
}

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
#define emp emplace
#define eb emplace_back
#define run(...) [&](){__VA_ARGS__}()
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;
const double EPS = 1e-9;

template <class info, class tag>
struct SegmentTree {
  int n, h;
  vec<info> d;
  vec<tag> lz;

  SegmentTree(int _n) : n(_n), h(0) {
    for(; 1 << h < n; h++);
    d.resize(n << 1);
    lz.resize(n);
  }

  // SegmentTree(const vec<info>& v) : SegmentTree(len(v)) {
  //   for(int i = 0; i < n; i++) d[i + n] = v[i];
  //   build();
  // }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void apply(int id, tag t, int k = 1) {
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

  void update(int id, info t) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    d[id] = t;
    for(id >>= 1; id; id >>= 1) pull(id);
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

  info query(int id) { // [id]
    id += n;
    for(int i = h; i; i--) push(id >> i, 1 << i);
    return d[id];
  }

  info query(int l, int r) { // [l, r)
    l += n, r += n;

    for(int i = h; i; i--) {
      if(l >> i << i != l) push(l >> i, 1 << i);
      if(r >> i << i != r) push((r - 1) >> i, 1 << i);
    }

    info resL, resR;
    for(; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, d[l++]);
      if(r & 1) resR = merge(d[--r], resR);
    }

    return merge(resL, resR);
  }
};

struct info {
  char c, d;
  info(char _c = ' ', char _d = ' ') {
    if(_c != ' ') c = _c;
    if(_d != ' ') d = _d;
  }

  friend info merge(info left, info right) {
    info res;
    return res;
  }
};

struct tag {
  char c;
  tag(char v = ' ') : c(v) {}

  bool empty() const {
    return false;
  }

  void apply(info& x, int k) const {
    if(c != ' ' && x.d == '.') x.c = c;
  }

  void combine(tag t) {
    if(t.c != ' ') c = t.c;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  
  SegmentTree<info, tag> seg(n);
  for(int i = 0; i < n; i++) seg.update(i, info('a', '.'));

  for(int t, x; q--;) {
    cin >> t;
    if(char c; t == 1) {
      cin >> x; x--;
      seg.update(x, info(seg.query(x).c, seg.query(x).d == '.' ? '#' : '.'));
    } else {
      cin >> c;
      seg.update(0, n, tag(c));
    }
    // for(int i = 0; i < n; i++) prin(seg.query(i).c);
    // print();
    // for(int i = 0; i < n; i++) prin(seg.query(i).d);
    // print();
  }
  
  for(int i = 0; i < n; i++) prin(seg.query(i).c);
  print();
  // print();

  // for(int i = 0; i < n; i++) prin(seg.query(i).d);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while (t--)
  solve();
}