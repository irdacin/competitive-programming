#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int x[4], y[4];
    for(int i=0;i<4;i++) cin >> x[i] >> y[i];
    sort(x,x+4);
    sort(y,y+4);
    int panjang = x[3]-x[0];
    int lebar = y[3]-y[0];
    cout << panjang*lebar;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}