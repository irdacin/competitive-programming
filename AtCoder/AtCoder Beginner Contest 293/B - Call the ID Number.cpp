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

    vector<bool> called(n, false);
    int idx=0;
    for(auto &i:a){
        if(!called[idx]) called[i-1] = true;
        idx++;
    }

    vector<int> ans;
    for(int i=1;i<=n;i++) if(!called[i-1]) ans.push_back(i);

    cout << len(ans) << endl;
    for(auto i:ans) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}