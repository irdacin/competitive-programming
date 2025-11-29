#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(auto &i:a) cin >> i;

	int ans=0, sum=0;
	map<int, int>mp;
	mp[0]++;
	for(auto &i:a){
		sum = (sum+i)%n;
		if(sum<0) sum+=n;
		ans+=mp[sum];
		mp[sum]++;
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