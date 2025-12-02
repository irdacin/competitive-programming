#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    int p[n];
    for(auto &i:p) cin >> i;
    sort(p,p+n);

    int ans=0;
    for(int i=0, j=n-1;i<=j;){
        if(p[i]+p[j]<=x) ans++, i++, j--;
        else if(p[j]<=x) ans++, j--;
        else if(p[i]<=x) ans++, i++;
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