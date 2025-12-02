#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

void solve(){
    int x,y; cin>>x>>y;
    cout << gcd(x,y)<<endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}