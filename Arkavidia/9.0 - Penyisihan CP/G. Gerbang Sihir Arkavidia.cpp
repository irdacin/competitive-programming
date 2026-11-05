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
const int INF = 2e18;

void solve() {
  int n, k; cin >> n >> k;
  vvvec<iii> adj(2, n);
  for(int a, b, c, t; k--;) cin >> a >> b >> c >> t, a--, b--, adj[0][a].eb(b, c, t), adj[1][b].eb(a, c, t);
  int x, y; cin >> x >> y; x--, y--;

  priority_queue<pii, vec<pii>, greater<pii>> pq;
  vec<int> dist(n, INF);
  dist[x] = 0;
  pq.emplace(0, x);

  while(!pq.empty()) {
    auto [dist_u, u] = pq.top(); pq.pop();
    if(u == y) return print(dist[u]);
    if(dist_u > dist[u]) continue;

    for(int i = 0; i < 2; i++) {
      for(auto [v, c, t] : adj[i][u]) {
        bool change = dist[u] / t & 1 ^ 1 == i;
        if(!change && dist[u] + c < dist[v]) {
          dist[v] = dist[u] + c;
          pq.emplace(dist[v], v);
        } else if(change && dist[u] + c + t - dist[u] % t < dist[v]) {
          dist[v] = dist[u] + c + t - dist[u] % t;
          pq.emplace(dist[v], v);
        }
      }
    }
  }

  print(-1);
}

signed main() {
  fastio;
  // #undef endl

  // precompute();
  // cout << fixed << setprecision(6);
  // int t; cin >> t; while(t--)
  solve();
}