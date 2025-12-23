#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x) 
#define len(x) (int) x.size()
using namespace std;

void solve(){
	int h, w, r, c; 
	cin >> h >> w >> r >> c;
	
	pair<int,int> dir[4] = {{0,1},{1,0},{-1,0},{0,-1}};
	int ans=0;
	for(auto [dx,dy]:dir){
		int x = r+dx, y = c+dy;
		if(x>0 && x<=h && y>0 && y<=w) ans++;
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