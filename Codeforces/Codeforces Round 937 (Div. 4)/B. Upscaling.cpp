#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;

    bool pagar = true;
    for(int i=0;i<2*n;i++){
        if(i%2==0) pagar^=1;
        for(int j=0;j<n;j++){
            pagar^=1;
            for(int k=0;k<2;k++){
                cout << (pagar ? '#':'.');
            }
        }
        if(n&1) pagar^=1;
        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve();
}