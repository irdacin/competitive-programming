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
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()

const int MOD = 1e9 + 7;
const int INF = 2e18;
const int MAXN = 2e5;

void solve(){
  int n, m; cin >> n >> m;

  vector<array<int, 4>> edge; 
  for(int u, v, red, blue; m--;){
    cin >> u >> v >> red >> blue;
    u--, v--;
    edge.pb({u, v, red, blue});
    edge.pb({v, u, red, blue});
  }

  vvec<int> dist(n, 2, INF); // 0 red 1 blue
  dist[0][0] = dist[0][1] = 0;

  for(int i = 0; i < n - 1; i++){
    for(auto [u, v, red, blue] : edge){
      dist[v][0] = min(dist[v][0], dist[u][1] + red);
      dist[v][1] = min(dist[v][1], dist[u][0] + blue);
    }
  }

  for(auto [u, v, red, blue] : edge){
    if(dist[u][1] + red < dist[v][0]) return print("abyss");
    if(dist[u][0] + blue < dist[v][1]) return print("abyss");
  }

  print(min(dist[n - 1][0], dist[n - 1][1]));
}

signed main(){
  // #define INTERACTIVE
  #ifdef INTERACTIVE
  #undef endl
  #else
  fastio;
  #endif

  // precompute();
  // cout << setprecision(6) << fixed;
  int t; cin >> t; for(int tc = 1; tc <= t; tc++)
  prin("Case #", tc, ": "),
  solve();
}