#include <bits/stdc++.h>
using namespace std;

// #define int long long
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

template <class info>
struct SegmentTree {
  using T = typename info::value_type;
  int n;
  vec<info> d;

  SegmentTree(int _n) : n(_n) {
    d.resize(n << 1);
  }

  SegmentTree(const vec<T>& v) : SegmentTree(len(v)) {
    for(int i = 0; i < n; i++) d[i + n] = info(v[i]);
    build();
  }

  void build() {
    for(int id = n - 1; id; id--) pull(id);
  }

  void pull(int id) {
    d[id] = merge(d[id << 1], d[id << 1 | 1]);
  }

  void update(int id, info t) { // [id]
    d[id += n] = t;
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  void update(int id, T t) { // [id]
    d[id += n].apply(t);
    for(id >>= 1; id; id >>= 1) pull(id);
  }

  info query(int id) { // [id]
    return d[id += n];
  }

  info query(int l, int r) { // [l, r)
    info resL, resR;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if(l & 1) resL = merge(resL, d[l++]);
      if(r & 1) resR = merge(d[--r], resR);
    }

    return merge(resL, resR);
  }
};

struct info {
  using value_type = pair<char, int>;
  array<int, 16> ar;
  info() {
    for(int i = 0; i < 16; i++) ar[i] = -1;
  }
  info(value_type v) {
    auto [t, k] = v;
    for(int i = 0; i < 16; i++) ar[i] = t == '+' ? (i + k) % 16 : i ^ k;
  }

  int& operator[](int i) {
    return ar[i];
  }

  friend info merge(info left, info right) {
    if(left[0] == -1) return right;
    if(right[0] == -1) return left;

    info res;
    for(int i = 0; i < 16; i++) res.ar[i] = right[left.ar[i]];
    return res;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vec<pair<char, int>> a(n);
  for(auto &[c, k] : a) cin >> c >> k;

  SegmentTree<info> seg(a);
  for(int i, k; q--;) {
    char t; cin >> i >> t >> k; i--;
    seg.update(i, info({t, k}));
    print(seg.query(0, n)[0]);
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}