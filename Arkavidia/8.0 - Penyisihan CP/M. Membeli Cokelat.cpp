#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n, x; cin >> n >> x;

	int a[n];
	for(auto &i:a) cin >> i;

	vector<int>graph[n];
	for(int i=0; i<n-1;i++){
		int u, v; cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int>chocolate(n, a[x-1]);
	vector<bool>visited(n, false);
	function<void(int)> dfs = [&](int node){
		// cout << node << " -> ";
	
		visited[node] = true;

		for(auto nextNode:graph[node]){
			if(!visited[nextNode]){
				chocolate[nextNode] = min(chocolate[node], a[nextNode]);
				dfs(nextNode);
			}
			
		}
	};

	dfs(x-1);
	for(auto &choco:chocolate) cout << choco << ' ';
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}