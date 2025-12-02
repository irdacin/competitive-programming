#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n, q;
    cin>>n >> q;
    ll a[n], dp[n+1];
    dp[0] = 0;
    for(int i=0;i<n;i++){
        cin >> a[i], dp[i+1]=dp[i]+a[i];
        if(i!=0 && a[i]<a[i-1]) a[i]=a[i-1];
    }

    while(q--){
        ll k; cin>>k;
        ll ans=-1;
        
        int left=0, right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(a[mid]<=k) ans=mid, left=mid+1;
            else right=mid-1;
        }
        
        cout << dp[ans+1] << ' ';
    }
    cout << endl;
}

int main(){
	ez;
	int t; cin >> t; while(t--)
	solve();
	return 0;
}