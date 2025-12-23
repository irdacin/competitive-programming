#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    if(x<=m && m<=n) cout << t;
    else{
        while(x --> m) t-=d;
        cout << t;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}