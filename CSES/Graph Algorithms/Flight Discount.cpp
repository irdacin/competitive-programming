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
const int INF = 2e18;

void solve(){
	int n, m; cin >> n >> m;
	vvec<pii> adj(n);
	for(int a, b, c; m--;) cin >> a >> b >> c, adj[--a].pb({--b, c});

	vvec<int> distance(n, 2, INF);
	using T = tuple<int, int, bool>;
	priority_queue<T, vec<T>, greater<T>> pq;
	distance[0][0] = distance[0][1] = 0;
	pq.push({0, 0, 0});

	while(!pq.empty()){
		auto [dist_u, u, used] = pq.top(); pq.pop();

		if(dist_u != distance[u][used]) continue;
		
		for(auto [v, cost] : adj[u]){
			if(!used && distance[u][used] + cost/2 < distance[v][!used]){
				distance[v][!used] = distance[u][used] + cost/2;
				pq.push({distance[v][!used], v, true});
			}
			if(distance[u][used] + cost < distance[v][used]){
				distance[v][used] = distance[u][used] + cost;
				pq.push({distance[v][used], v, used});
			}
		}
	}

	// cout << distance << endl;
	cout << distance[n-1][1];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}