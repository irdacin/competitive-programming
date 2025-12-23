#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int k, g, m;
    cin >> k >> g >> m;
    int glass=0, mug=m;
    while(k-->1){
        if(glass==g) glass=0;
        else if(mug==0) mug+=m;
        else {
            int need = min(g-glass, mug); 
            glass+=need, mug-=need;
        }
    }
    cout << glass << ' ' << mug;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}