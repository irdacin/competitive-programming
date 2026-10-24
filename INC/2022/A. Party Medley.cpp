#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
	int a[n];
	for(auto &i:a) cin >> i;
	sort(a,a+n);

	auto max3=[](int a, int b, int c){
		return max(max(a,b),c);
	};

	auto min3=[](int a, int b, int c){
		return min(min(a,b),c);
	};

	int cnt=0, ans=0;
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for(int k=j+1;k<n;k++)
				if(max3(a[i],a[j],a[k])-min3(a[i],a[j],a[k]) <= m) cnt++,
				ans = max(ans, a[i] + a[j]+ a[k]);

	cnt ? cout << cnt << ' ' << ans : cout << --cnt; 
}

int main(){
	ez;
	// int t; cin >> t; while(t--)
	solve();
	return 0;
}