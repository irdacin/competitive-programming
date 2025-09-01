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

template <typename T>
struct FenwickTree {
  int n;
  vec<T> bit;

  FenwickTree(int _n) : n(_n + 1) {
    bit.resize(n);
  }

  FenwickTree(const vec<int>& v) : FenwickTree(len(v)) {
    for(int i = 0; i < len(v); i++)
      update(i, v[i]);
  }

  void update(int pos, T val) {
    for(++pos; pos < n; pos += pos & -pos) 
      bit[pos] += val;
  }

  T query(int pos) {
    T res = 0;
    for(++pos; pos > 0; pos -= pos & -pos)
      res += bit[pos];
    return res;
  }

  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void solve() {
  int n; cin >> n;

  vec<iii> events;
  for(int x1, y1, x2, y2; n--;) {
    cin >> x1 >> y1 >> x2 >> y2;
    if(y1 == y2) {
      events.eb(x1, 1, y1, y2);
      events.eb(x2 + 1, -1, y1, y2);
    } else events.eb(x1, 2, y1, y2);
  }

  sort(all(events));
  FenwickTree<int> fen(100'001);
  int ans = 0;

  for(auto [x, d, y1, y2] : events) {
    if(d == 2) ans += fen.query(y1, y2);
    else fen.update(y1, d);
  }

  print(ans);
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}