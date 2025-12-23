#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(auto &i:a) cin >> i;

    int ans = 1;
    for(int cur=0; auto i:a){
        cur+=i;
        if(cur > k) ans++, cur = i;
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