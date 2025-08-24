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
using iii = tuple<int, int, int, int>;
#define fi first
#define se second
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define len(x) (int)(x).size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;
const double EPS = 1e-9;

void solve() {
  int n, m, q; cin >> n >> m >> q;
  vec<int> a(n); cin >> a;

  vec<iii> queries(q);
  for(int i = 0; auto &[l, r, x, id] : queries) cin >> l >> r >> x, l--, r--, id = i++;

  const int BLOCK = sqrt(n);
  sort(all(queries), [BLOCK](auto &a, auto &b) {
    auto [l1, r1, x1, id1] = a;
    auto [l2, r2, x2, id2] = b;
    if(l1 / BLOCK != l2 / BLOCK) return l1 < l2;
    return r1 < r2;
  });

  vec<int> color(m + 1);

  auto add = [&](int x) {
    color[x]++;
  };

  auto del = [&](int x) {
    color[x]--;
  };

  vec<int> ans(q);
  for(int curL = 0, curR = -1; auto [l, r, x, id] : queries) {
    while(curL < l) del(a[curL++]);
    while(curR > r) del(a[curR--]);
    while(curL > l) add(a[--curL]);
    while(curR < r) add(a[++curR]); 
    ans[id] = color[x];
  }

  for(auto x : ans) print(x);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}