#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl '\n'
#define rcout(x) return void(cout << x)

template <typename T> istream& operator>>(istream& is, vector<T>& _v) { for(auto &x : _v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> _v) { int _n=_v.size(); for(int _i=0; _i<_n; _i++) os << _v[_i] << (_i==_n-1 ? "":" "); return os; }
template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& _p) { is >> _p.first >> _p.second; return is; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U> _p) { os << _p.first << ' ' << _p.second; return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const vector<pair<T, U>> _v) { for(auto _i : _v) os << _i << endl; return os; }
template <typename T> struct vec : vector<T> { using vector<T>::vector; };
template <typename T> struct vvec : vec<vec<T>> {
	vvec(initializer_list<initializer_list<T>> _list) { for(const auto& _row : _list) this->push_back(_row); }
	vvec(int _n = 0, int _m = 0, const T& _init_value = T()) : vec<vec<T>>(_n, vec<T>(_m, _init_value)) {}
    friend ostream& operator<<(ostream &os, const vvec _v) { for(auto _i : _v) os << _i << endl; return os; }
};
template <typename T> struct vvvec : vec<vvec<T>> {
	vvvec(initializer_list<initializer_list<initializer_list<T>>> _list) { for(const auto& _rows : _list) for(const auto& _row : _rows) this->push_back(_row); }
	vvvec(int _n = 0, int _m = 0, int _k = 0, const T& _init_value = T()) : vec<vvec<T>>(_n, vvec<T>(_m, _k, _init_value)) {}
    friend ostream& operator<<(ostream &os, const vvvec _v) { for(auto _row : _v) for(auto _i : _row) os << _i << endl; return os; }
};
#define pb push_back
#define all(x) x.begin(), x.end()
#define len(x) (int) x.size()
#define pii pair<int, int>
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 2e9;

void solve(int n, int m, int q, int s){
	vvec<pii> adj(n);
	for(int u, v, w; m--;) cin >> u >> v >> w, adj[u].pb({v, w});

	vec<int> distance(n, INF);
	priority_queue<pii, vec<pii>, greater<pii>> pq;
	distance[s] = 0;
	pq.push({0, s});

	while(!pq.empty()){
		auto [dist_u, u] = pq.top(); pq.pop();

		if(distance[u] != dist_u) continue;
		
		for(auto [v, w] : adj[u]){
			if(distance[u] + w < distance[v]){
				distance[v] = distance[u] + w;
				pq.push({distance[v], v});
			}
		}
	}
	
	for(int s; q--;){
		cin >> s;
		distance[s]==INF ? cout << "Impossible" : cout << distance[s];
		cout << endl;
	}

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
	for(int n, m, q, s; cin >> n >> m >> q >> s;) if(n)
    solve(n, m, q, s), cout << endl;
}