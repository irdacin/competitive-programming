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

struct SparseTable {
  int n;
  vec<int> lg;
  vvec<int> table;

  SparseTable() {}
  SparseTable(const vec<int>& v) : n(len(v)) {
    lg.resize(n + 1);
    lg[1] = 0;
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    table.resize(lg[n] + 1, vec<int>(n));
    for(int i = 0; i < n; i++) table[0][i] = v[i];
    for(int k = 1; k <= lg[n]; k++) {
      for(int i = 0; i + (1 << k) <= n; i++) {
        table[k][i] = merge(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
      }
    }
  }

  int merge(int left, int right) {
    return max(left, right);
  }

  int query(int l, int r) {
    // l--, r--;
    int k = lg[r - l + 1];
    return merge(table[k][l], table[k][r - (1 << k) + 1]);

    int res = INF;
    for(; k >= 0; k--) {
      if((1 << k) <= r - l + 1) {
        res = merge(res, table[k][l]);
        l += 1 << k;
      }
    }

    return res;
  }
};

void solve() {
  int n; cin >> n;
  vec<int> t(n); cin >> t;

  SparseTable st(t);
  int q; cin >> q;
  
  for(int l, r; q--;) {
    cin >> l >> r; l--, r--;
    print(t[l] == t[r] && st.query(l + 1, r - 1) <= t[l] ? "YA" : "TIDAK"); 
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}