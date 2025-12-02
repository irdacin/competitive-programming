#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    sort(a,a+n);
    sort(b,b+m);

    int ans=0;
    for(int i=0,j=0;i<n&&j<m;){
        if(abs(a[i]-b[j])<=k) ans++, i++, j++;
        else if(a[i]<b[j]) i++;
        else j++;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}