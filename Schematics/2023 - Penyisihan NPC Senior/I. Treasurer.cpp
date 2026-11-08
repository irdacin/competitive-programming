#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int v; cin >> v;
	vector<int> a(v);
	for(auto &i:a) cin >> i;

	vector<vector<pair<int,int>>> graph(v);
	for(int i=0; i<v; i++){
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back({y,w});	
		graph[y].push_back({x,w});	
	}

	int n, m; cin >> n >> m;

	vector<bool> vis(v, false);
	vis[n] = true;

	vector<vector<int>> dp(v, vector<int>(m+1, -1));
	auto func = [&](auto func, int vertex, int food) -> int{

		int &res = dp[vertex][food];
		if(res!=-1) return res;
		
		res = 0;
		for(auto [next, bobot]:graph[vertex]){
			int sum = 0;
			if(!vis[next] && food >= bobot){
				vis[next] = true;
				sum += func(func, next, food-bobot) + a[next];
				vis[next] = false;
			}
			res = max(res, sum);
		}
		return res;
	};

	cout << func(func, n, m) + a[n];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}