#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int,vector<int>>graph;
	while(n-->1){
		int u, v;
		cin >> u >> v;
		graph[--u].push_back(--v);
		graph[v].push_back(u);
	}

	vector<int>count(graph.size(),0);
	function<void(int, int)> dfs = [&](int vertex, int root){
		if(graph[vertex].size()==1 && graph[vertex][0]==root) return void(count[vertex]=1);
		
		for(auto curVertex:graph[vertex]){
			if(curVertex==root) continue;
			dfs(curVertex, vertex);
			count[vertex]+=count[curVertex];
		}
		
	};

	dfs(0,-1);
	// for(auto c:count) cout << c << ' ';

	int q, x, y;
	cin >> q;
	while(q--) cout << (cin>> x, cin >> y, count[--x]*count[--y]) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve();
}