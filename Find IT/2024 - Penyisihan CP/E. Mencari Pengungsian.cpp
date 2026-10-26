#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    int x[n];
    for(auto &i:x) cin >> i;
    sort(x, x+n);

    int pref[n+1];
    for(int idx=0, sum=0; auto &i:pref) i=sum, sum += x[idx++];
    // for(auto i:pref) cout << i << ' '; cout << endl;

    while(q--){
        int l, r;
        cin >> l >> r;

        int ans = 0;
        
        int pos = 0;
        for(int left=0, right=n-1; left<=right;){
            int mid = left+right >> 1;
            if(x[mid] < l) left=mid+1;
            else pos = mid, right=mid-1;
        }
        ans+= l*pos - pref[pos];

        pos = n;
        for(int left=0, right=n-1; left<=right;){
            int mid = left+right >> 1;
            if(x[mid] < r) left=mid+1;
            else pos = mid, right=mid-1;
        }

        ans+= pref[n]-pref[pos] - r*(n-pos);
        cout << ans << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}