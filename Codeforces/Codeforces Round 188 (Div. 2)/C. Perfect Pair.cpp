#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int x, y, m;
	cin >> x >> y >> m;
	int ans=0;
	while(x<m && y<m){
		if(x<=0 && y<=0) return void(cout << -1);
		if(x>y) swap(x,y);
		if(x<0) ans+= abs(x)/y, x+=abs(x)/y*y;

		x = x+y;
		// cout << x << ' '  << y << endl;
		ans++;
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