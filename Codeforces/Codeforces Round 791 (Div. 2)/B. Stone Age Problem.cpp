#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    int a[n], sum=0;
    for(auto &i:a) cin >> i, sum+=i;

    int value = -1;
    bool changed[n];
    memset(changed, 0, sizeof(changed));
    while(q--){
        int ask; cin >> ask;

        if(ask==1){
            int i, x;
            cin >> i >> x;
            sum-= changed[i-1] ? value : a[i-1];
            changed[i-1] = false;
            a[i-1] = x;
            sum += a[i-1];
        } else {
            int x; 
            cin >> x;
            value = x;
            memset(changed,1,sizeof(changed));
            sum = n*x;
        }

        cout << sum << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}