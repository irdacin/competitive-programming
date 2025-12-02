#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    ll a[n];
    for(auto &i:a) cin >> i;

    // ll max = -1;
    // for(int i=0;i<n-1;i++){
    //     ll sum=a[i];
    //     for(int j=i+1;j<n;j++){
    //         sum+=(ll) a[j];
    //         if(sum>max) max = sum;
    //     }
    // }
    // cout << max << endl;

    ll dp[n];
    dp[0] = a[0];
    for(int i=1;i<n;i++)
        dp[i] = max(a[i], dp[i-1]+a[i]);
    
    ll max = LLONG_MIN;
    for(auto &i:dp)
        if(i>max) max=i;
    cout << max << endl;
    
}

int main(){
	ez;
	// int t; cin >> t; while(t--)
	solve();
	return 0;
}