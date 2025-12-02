#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k, q; 
    cin >> n >> k >> q;
    int a[k], b[k];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    while(q--){
        int d; cin >> d;

        int pos = k-1;
        for(int left=0, right=k-1; left<=right;){
            int mid = left+(right-left)/2;
            if(a[mid]<=d) left=mid+1;
            else pos=mid, right=mid-1;
        }

        int distance = a[pos], time = b[pos];
        if(pos>0) distance -= a[pos-1], time -= b[pos-1];

        int ans = d*time/distance;
        if(pos>0) ans= (d-a[pos-1])*time/distance + b[pos-1];

        cout << ans << ' ';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}