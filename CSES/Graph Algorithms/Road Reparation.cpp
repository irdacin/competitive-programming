#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()

#define vi vector<int>
#define vvi vector<vi>

const int MOD = 1e9 + 7;

struct DSU {
	int n;
	vi parent, rank;

	DSU(int n) : n(n), parent(n), rank(n, 0) {
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u){
		return parent[u] == u ? u : parent[u] = find(parent[u]);
	}

	bool unite(int u, int v){
		u = find(u);
		v = find(v);
		if(u == v) return false;

		if(rank[u] < rank[v])
			swap(u, v);
		
		parent[v] = u;
		rank[u] += rank[v];

		return true;
	}
};

void solve(){
	int n, m; cin >> n >> m;

	array<int, 3> roads[m];
	for(auto &[u, v, cost]:roads) cin >> u >> v >> cost, u--, v--;

	sort(roads, roads+m, [](auto a, auto b){
		return a[2] < b[2];
	});

	DSU dsu(n);

	int cnt = 0, min_cost = 0;
	for(auto [u, v, cost]:roads){
		bool status = dsu.unite(u, v);
		if(status) min_cost += cost, cnt++;
	}

	cnt != n - 1 ? cout << "IMPOSSIBLE" : cout << min_cost;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}