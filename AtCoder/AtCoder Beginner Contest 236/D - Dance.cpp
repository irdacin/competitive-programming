#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int n; cin >> n;
	vector<vector<int>> a(2*n, vector<int>(2*n));
	for(int i=0;i<2*n-1;i++){
		for(int j=i+1;j<2*n;j++) cin >> a[i][j];
	}

	vector<pair<int,int>> dance;
	vector<bool> vis(2*n, false);
	auto func = [&](auto func){
		if(len(dance)==n){
			int res = 0;
			for(auto [i,j]:dance) res^=a[i][j];
			return res;
		}

		int i=0;
		for(;i<2*n && vis[i];i++);
		vis[i] = true;

		int res = 0;
		for(int j=0;j<2*n;j++){
			if(!vis[j]){
				vis[j] = true;
				dance.push_back({i,j});
				res = max(res, func(func));
				dance.pop_back();
				vis[j] = false;
			}
		}

		vis[i] = false;
		return res;
	};

	cout << func(func);
} 

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}