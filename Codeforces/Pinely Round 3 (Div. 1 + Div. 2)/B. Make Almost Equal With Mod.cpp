#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n; cin >> n;
	int a[n];
	for(auto &i:a) cin >> i;

	for(int k=1;k<=1e18;k*=2){
		set<int>st;
		for(auto i:a) i%=k, st.insert(i);
		if(st.size()==2) return void(cout<<k);
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}