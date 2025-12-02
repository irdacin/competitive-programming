#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    int even = 0, odd = 0;
    for(int i=0;i<n;i++){
        if(i&1) even+=a[i]%2 ? 0:1;
        else odd+=a[i]%2 ? 1:0;
    }  
    // cout << even << ' ' << odd;

    // if(odd==0) cout << 0;
    if(odd==even) cout << odd;
    else cout << -1;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}