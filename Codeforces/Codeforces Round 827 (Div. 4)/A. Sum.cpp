#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int a[3];
    for(auto&i:a) cin>>i;
    sort(a,a+3);
    cout << (a[0]+a[1]==a[2] ? "YES":"NO") << endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}