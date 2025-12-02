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
inline void prin(T &&A = "", U &&...B) { cout << A; if (sizeof...(U)) prin(B...); }
template <typename T, typename... U>
inline void print(T &&A, U &&...B) { prin(A); if (sizeof...(U)) prin(' '); print(B...); }
template <typename T> inline void printsp(T &&A, const char* sp = " ") { prin(A, sp); }

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

const int MOD = 1e9 + 7;
const int INF = 2e9;
const int MAXN = 2e5;

void solve(){
  int n, m; cin >> n >> m;
  vec<int> x(n), r(n); cin >> x >> r;

  vvec<pii> v(m + 1);
  for(int i = 0; i < n; i++){
    for(int y = 0; y <= r[i]; y++){

      int d = (int) sqrt((double) (r[i] * r[i] - y * y)); 
      v[y].eb(x[i] - d, x[i] + d);
    }
  }

  int ans = 0;
  for(int y = 0; y <= m; y++){
    sort(all(v[y]));

    int cnt = 0;
    
    for(int i = 0; i < len(v[y]); i++){
      int left = v[y][i].fi, right = v[y][i].se;
      
      for(; i < len(v[y]) && v[y][i].fi <= right + 1; i++){
        right = max(right, v[y][i].se);
      }
      
      i--;
      cnt += right - left + 1;
    }
    
    if(y > 0) cnt *= 2;
    // debug(cnt);

    ans += cnt;
  }

  print(ans);
}

signed main(){
  fastio;
  // #undef endl

  // precompute();
  // cout << setprecision(6) << fixed;
  int t; cin >> t; while(t--)
  solve();
}