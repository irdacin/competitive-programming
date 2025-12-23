#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()

#define vi vector<int>
#define vvi vector<vi>

const int MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> vec;
    for(int i=0; i<n; i++){
        int l, r; cin >> l >> r;
        vec.push_back({l, 1});
        vec.push_back({r+1, -1});
    }
    sort(vec.begin(), vec.end());

    int ans = 0, cur = 0;
    for(auto [i, f]:vec){
        cur += f;
        if(f==-1) ans += cur;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}