#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n=s.length();
    string ans="";
    for(int i=n-1;i>=0;i--){
        if(s[i]=='.') exit(ans);
        ans=s[i]+ans;
    }
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}