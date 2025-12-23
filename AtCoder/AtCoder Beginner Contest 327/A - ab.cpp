#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
	int n; string s;
    cin >> n >> s;
    // int a=0, b=0;
    // for(auto &c:s) if(c=='a') a++; else if(c=='b') b++;
    // cout << (a&&b? "Yes":"No") ;

    for(int i=0;i<n-1;i++) if(s[i]=='a' && s[i+1]=='b' || s[i]=='b' && s[i+1]=='a') exit("Yes");
    cout << "No";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t; cin >> t; while(t--)
	solve(), cout << endl;
}