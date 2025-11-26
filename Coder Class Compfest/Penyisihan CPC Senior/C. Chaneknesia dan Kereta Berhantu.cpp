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

void solve() {
  int n; cin >> n;

  vvec<pii> kanan(2), kiri(2);
  for(int u, v, i = 0; i < n; i++) {
    cin >> u >> v;

    if(u < v) kanan[u & 1].eb(v - u, u);
    else kiri[u & 1].eb(u - v, u);
  }
  for(int i = 0; i < 2; i++) sort(all(kanan[i]));
  for(int i = 0; i < 2; i++) sort(all(kiri[i]));
  print(kanan);
  print(kiri);
  int ans = 0;
  for(int i = 0; i < 2; i++) {
    for(auto [d, u] : kiri[i]) {

      int posLeft = len(kanan);
      for(int left = 0, right = len(kanan[i]) - 1; left <= right;) {
        int mid = (left + right) / 2;
        if(kanan[i][mid].fi + kanan[i][mid].se <= d + u) posLeft = mid, left = mid + 1;
        else right = mid - 1;
      }
      
      int posRight = -1;
      for(int left = 0, right = len(kanan[i]) - 1; left <= right;) {
        int mid = (left + right) / 2;
        if(kanan[i][mid].fi + kanan[i][mid].se >= d + u) posRight = mid, right = mid - 1;
        else left = mid + 1;
      }

      print(posLeft, posRight);

    }
  }
}

signed main() {
  fastio;
  // cout << fixed << setprecision(6);

  // precompute();
  // int t; cin >> t; while(t--)
  solve();
}