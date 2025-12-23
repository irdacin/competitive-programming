#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int p[n];
    for(auto &i:p) cin >> i;

    int q; cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        int i=0, j=0;
        for(;p[i]!=a;i++);
        for(;p[j]!=b;j++);

        cout << p[min(i,j)] << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}