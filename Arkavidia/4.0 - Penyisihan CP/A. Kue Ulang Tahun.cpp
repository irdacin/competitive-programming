#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n; cin >> n;
    int a[n];
    for(auto &i:a) cin>> i;
    
    int mn = a[0];
    for(auto &i:a) mn= min(mn, i);
    int ans=0;
    for(auto &i:a) ans+=i-mn;
    cout << ans << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; while(t--)
	solve();
}