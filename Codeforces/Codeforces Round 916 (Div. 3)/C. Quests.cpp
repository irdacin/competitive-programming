#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n, k; 
	cin >> n >> k;
	int a[n], b[n];
	for(auto &i:a) cin >> i;
	for(auto &i:b) cin >> i;

	int prefA[n], prefB[n];
	for(int i=0;i<n;i++) 
		prefA[i]=i==0?a[i]:a[i]+prefA[i-1], 
		prefB[i]=i==0?b[i]:max(b[i], prefB[i-1]);
	
	// for(auto &i:prefA) cout << i << ' '; cout << endl;
	// for(auto &i:prefB) cout << i << ' '; cout << endl;

	int ans=0;
	for(int i=0;i<n;i++){
		if(i>=k) break;
		
		int temp = prefA[i];
		int need = k-i-1;
		temp+=need*prefB[i];
		if(temp>ans) ans=temp;
	}
	cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}