#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int h, w, n;
	cin >> h >> w >> n;
	char dir[n];
	for(auto &i:dir) cin >> i;
	vector<vector<char>>grid(h, vector<char>(w));
	for(auto &row:grid) for(auto &col:row) cin >> col;

	auto valid = [&](int row, int col){
		return row>=0 && row<h && col>=0 && col<w;
	};

	function<bool(int,int,int)> dfs = [&](int i, int j, int cnt){
		if(!valid(i,j)) return false;
		if(grid[i][j]=='#') return false;
		if(cnt==n) return true;

		if(dir[cnt]=='L') j--;
		else if(dir[cnt]=='R') j++;
		else if(dir[cnt]=='U') i--;
		else i++;

		return dfs(i, j, cnt+1);
	};

	int ans=0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(grid[i][j]=='.') if(dfs(i, j, 0)) ans++;
		}
	}

	cout << ans;

}	

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}