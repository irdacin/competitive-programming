#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << x << endl

template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& _v) {
  for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}
inline void print() { cout << endl; }
template <typename T = const char*, typename... U> 
inline void prin(T&& A = "", U&&... B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T&& A, U&&... B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T&& A, const char* sp = " ") { prin(A, sp); }

template <typename T> struct vec : vector<T> { using vector<T>::vector; };
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
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7; // 998244353;
const int INF = 2e9;

void solve() {
  int n, m; cin >> n >> m;
  vec<int> a(n), b(m); cin >> a >> b;

  vec<int> pref(m, -1);
  int j = 0;
  for(int i = 0; i < n && j < m; i++) {
    if(a[i] >= b[j]) {
      pref[j] = i;
      j++;
    }
  }

  if(j == m) return print(0);

  vec<int> suff(m, -1);
  for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
    if(a[i] >= b[j]) {
      suff[j] = i;
      j--;
    }
  }

  // print(pref);
  // print(suff);

  int ans = INF;
  for(int j = 0; j < m; j++) {
    int left = j > 0 ? pref[j - 1] : -2;
    int right = j < m - 1 ? suff[j + 1] : n + 2;
    if(left == -1 || right == -1) continue;

    if(left < right) 
      ans = min(ans, b[j]);
  }

  print(ans == INF ? -1 : ans);
}

signed main() {
  fastio;
  // #undef endl

  // precompute();
  // cout << fixed << setprecision(6);
  int t; cin >> t; while(t--)
  solve();
}