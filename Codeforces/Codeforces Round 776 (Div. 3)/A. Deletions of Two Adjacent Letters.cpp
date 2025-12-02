#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    string s; char c;
	cin >> s >> c;
	for(int i=0;i<s.length();i+=2)
		if(s[i]==c){
			cout << "YES" << endl;
			return;
		}
	cout << "NO" << endl;	
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve();
}