#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void multiply(int F[2][2], int M[2][2], int m){
	int res[2][2];
	memset(res,0,sizeof(res));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				res[i][j] += (F[i][k]%m * M[k][j]%m)%m,
				res[i][j]%=m;

	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			F[i][j] = res[i][j]%m;
}

void power(int F[2][2], ll n, int m){
	if(n==0 || n==1) return;
	int M[2][2] = {{1,1}, {1,0}};

	power(F, n/2, m);
	multiply(F, F, m);
	if(n&1) multiply(F, M, m);
}

int fibo(ll n, int m){
	if(n==0) return 0;
	int F[2][2] = {{1,1}, {1,0}};
	power(F, n-1, m);
	return F[0][0];
}

int cases = 1;
void solve(){
	ll n; int m; cin >> n>>m;
	cout << "Case #" << cases++ <<  ": " << fibo(n,m)%m << endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}