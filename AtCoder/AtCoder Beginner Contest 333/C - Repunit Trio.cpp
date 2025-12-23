#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin>> n;
    
    int repunits[13];
    repunits[0] = 1;
    for(int i=1;i<13;i++) repunits[i] = repunits[i-1] * 10 + 1;
    
    vector<int> ans;
    for(auto &i:repunits)
        for(auto &j:repunits)
            for(auto &k:repunits)
                ans.push_back(i+j+k);

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    // for(auto &i:ans) cout << i << ' ';


    cout << ans[n-1] << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}