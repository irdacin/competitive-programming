#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
	int n; cin >> n;
	int a[n];
	set<int>num;
	for(auto &i:a) cin >> i, num.insert(i);

	if(num.size()!=n) return void(cout << "NO");
	// int left=1, right=1e18;
	// while(left<=right){
	// 	int mid=left+(right-left)/2;
	// 	bool flag=false;
	// 	for(int i=0;i<n&&!flag;i++){
	// 		for(int j=i+1;j<n&&!flag;j++){
	// 			int fpb=gcd(a[i]+mid,a[j]+mid);
	// 			if(fpb!=1) flag=true;
	// 			cout << mid << ' '  << fpb << endl;
	// 		}
	// 	}
	// 	if(!flag) return void(cout << "YES");
	// 	// left=mid+1;
	// 	right=mid-1;
	// }
	// cout << "NO";

	for(int p=2;p*2<=n;p++){
		vector<int> cnt(p,0);
		for(auto &i:a) cnt[i%p]++;
		if(*min_element(cnt.begin(),cnt.end())>1) return void(cout << "NO");
	}
	cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}