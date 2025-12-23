#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;
    
    int m; cin >> m;
    int b[m];
    for(auto &i:b) cin >> i;
    
    int l; cin >> l;
    int c[l];
    for(auto &i:c) cin >> i;

    set<int> st;
    for(auto i:a) for(auto j:b) for(auto l:c) st.insert(i+j+l);        

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(st.find(x)!=st.end()) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}