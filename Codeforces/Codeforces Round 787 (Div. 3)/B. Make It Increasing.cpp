#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    int prev = a[n-1], ans = 0;
    for(int i=n-2;i>=0;i--){
        while(a[i]>0 && a[i]>=prev) a[i]/=2, ans++;
        // cout << a[i] << ' ' << prev << endl;
        if(a[i]>=prev) exit(-1);
        prev=a[i];
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