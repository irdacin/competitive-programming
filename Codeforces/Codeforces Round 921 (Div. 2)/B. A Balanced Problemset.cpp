#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int x, n;
    cin >> x >> n;
    int ans=1;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(x/i>=n) ans=max(ans,i);
            if(i>=n) ans=max(ans,x/i);
        }
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