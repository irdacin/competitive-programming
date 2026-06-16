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
template <typename T> inline void printsp(T &A, const char* sp = " ") { prin(A, sp); }

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

void solve(int n, int m){
	vec<pii> nodes(n);
	for(auto &[x, y] : nodes) cin >> x >> y;

	auto calc = [](pii u, pii v){
		auto [x1, y1] = u;
		auto [x2, y2] = v;

		return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	};

	vvec<bool> vis(n, n, false);
	vvec<double> preCost(n, n, INF);
	for(int i = 0; i < n; i++) preCost[i][i] = 0, vis[i][i] = true;
	for(int u, v; m--;){
		cin >> u >> v;
		u--, v--;

		preCost[u][v] = preCost[v][u] = calc(nodes[u], nodes[v]);
		vis[u][v] = vis[v][u] = true;
	}

	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				preCost[i][j] = min(preCost[i][j], preCost[i][k] + preCost[k][j]);
			}
		}
	}

	int maxCost = -INF;
	pii ans;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(vis[i][j]) continue;
			
			vvec<double> curCost = preCost;
			int dist = calc(nodes[i], nodes[j]); 

			for(int u = 0; u < n; u++){
				for(int v = 0; v < n; v++){
					curCost[u][v] = min(curCost[u][v], curCost[i][u] + curCost[j][v] + dist);
				}
			}

			// debug(i+1), debug(j+1);
			// for(auto x : preCost) print(x); print();
			// for(auto x : curCost) print(x); print();

			int cost = 0;
			for(int u = 0; u < n; u++){
				for(int v = 0; v < n; v++) cost += preCost[u][v] - curCost[u][v];
			}
			// debug(cost), print();

			if(cost <= 1.0) continue;

			if(maxCost < cost){
				maxCost = cost;
				ans = {i + 1, j + 1};
			}
		}
	}

	if(maxCost == -INF) print("No road required");
	else print(ans);
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
	// int t; cin >> t; while(t--)
	for(int n, m; cin >> n >> m && n && m;)
	solve(n, m);
}