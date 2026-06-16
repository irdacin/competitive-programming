#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define debug(x) cout << #x << " => " << x << endl

inline void print() { cout << endl; }
template <typename T = const char*, typename... U> inline void prin(T &&A = "", U &&...B) {
  cout << A; if (sizeof...(U)) prin(B...);
}
template <typename T, typename... U> inline void print(T &&A, U &&...B) {
  prin(A); if (sizeof...(U)) prin(' '); print(B...);
}
template <typename T> inline void printsp(T &A, const char* sp = " ") { prin(A, sp); }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& _p) {
  os << _p.first << ' ' << _p.second; return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& _v) {
  for(auto &_i : _v) { is >> _i; } return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& _v) {
  for(auto &_i : _v) { os << _i; if(&_i != &_v.back()) os << ' '; } return os;
}

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
const int INF = 2e18;
const int MAXN = 2e5;

void solve(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;

	vvec<pii> adj(n);
	for(int u, v, w; m--;){
		cin >> u >> v >> w;
		adj[u].eb(v, w);
		adj[v].eb(u, w);
	}

	vec<int> dist(n, INF);
	priority_queue<pii, vec<pii>, greater<pii>> pq;
	pq.emplace(0, s);
	dist[s] = 0;

	while(!pq.empty()){
		auto [d, u] = pq.top(); pq.pop();
		if(u == t) return print(d);
		if(d > dist[u]) continue;

		for(auto [v, w] : adj[u]){
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}

	print("unreachable");
}

signed main(){
  // #define INTERACTIVE
  #ifdef INTERACTIVE
  #undef endl
  #else
  fastio;
  #endif

  // precompute();
  int t; cin >> t; for(int tc = 1; tc <= t; tc++)
	prin("Case #", tc, ": "),
  solve();
}