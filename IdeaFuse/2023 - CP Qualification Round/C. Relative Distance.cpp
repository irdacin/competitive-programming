#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int cases = 1;
void solve(){
	string s;
	int k;
	cin >> s >> k;

	int n = s.length();
	string ans="";
	for(int i=0;i<n;i++) ans+='a';

	int sum = 0;
	for(int i=0;i<n;i++) sum+= s[i]-ans[i];

	for(int i=n-1;i>=0;i--){
		if(k==sum) break;

		int dif = s[i] - ans[i];
		int zdif = 'z' - s[i];
		if(sum-k>0){
			if(sum-dif >= k) sum-= dif, ans[i] = s[i];
			else ans[i]+= sum-k, sum=k;
		}

		else { 
			if(zdif > dif) if(sum+zdif-dif <= k)  sum+=(zdif-dif), ans[i]='z';
			else ans[i]+= k-sum+dif+dif, sum=k;
		}

		// cout << sum << ' ' << ans << endl;
	}

	cout << "Case #" << cases++ << ": ";
	cout << (sum==k ? ans : "-1");
	cout << endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t; while(t--)
	solve();
}