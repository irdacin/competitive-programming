#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int q; cin >> q;
    vector<int>a;
    while(q--){
        int type, value;
        cin >> type >> value;
        if(type==1) a.push_back(value);
        else cout << a[len(a)-value] << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}