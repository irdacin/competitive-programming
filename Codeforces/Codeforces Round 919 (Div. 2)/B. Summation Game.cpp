#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    int a[n];
    for(auto &i:a) cin >> i;
    sort(a,a+n,greater<int>());

    int pref[n+1];
    pref[0]=0;
    for(int i=1;i<=n;i++) pref[i] = pref[i-1]+a[i-1];
    // for(auto &i:pref) cout << i << ' ';

    int ans=LLONG_MIN;
    for(int i=0;i<=k;i++){
        int sum=0;

        // use brute force
        // int j=i;
        // for(;j<min(i+x,n);j++) sum-=a[j];
        // for(;j<n;j++) sum+=a[j];

        // use prefix sum
        sum-=(pref[min(i+x,n)] - pref[i]);
        sum+=(pref[n] - pref[min(i+x,n)]);
        // cout << sum << endl;
        ans = max(ans, sum);
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}