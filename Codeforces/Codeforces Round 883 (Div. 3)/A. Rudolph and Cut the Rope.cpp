#include <bits/stdc++.h>
#define start ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n;
	cin >> n;

	int ans=0;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		if(a>b) ans++; 
	}
	cout << ans << endl;
}

int main(){
    start;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}