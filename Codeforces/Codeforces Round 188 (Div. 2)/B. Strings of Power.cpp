#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	string s;
	cin >> s;

	int ans=0, h=0;
	int n = s.length();
	for(int i=0;i<n-4;i++){
		string temp="";
		for(int j=i;j<i+5;j++) temp+=s[j];
		// cout << temp << endl;

		if(temp=="heavy") h++, i+=4;
		else if(temp=="metal") ans+=h, i+=4;
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