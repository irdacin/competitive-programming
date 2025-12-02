#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    
    int ans = n;
    for(int left=1, right=32;left<right;){
        int mid = (left+right)/2;
        int res = 1<<mid;
        if(res<=n) ans = res, left=mid+1;
        else right=mid;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}