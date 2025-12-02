#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    ll n, c;
    cin >> n >> c;
    
    ll s[n];
    for(auto &a:s) cin >> a;
    
    ll left=1, mid,
    right = sqrt(c);
    while(left<=right){
        mid = (left+right)/2;
    
        ll res=0;
        for(auto &a:s){
            res += (a+2*mid) * (a+2*mid);
            if(res>c) break;
        }
        if(res==c) break;
        else if(res<c) left=mid+1;
        else right=mid-1;
    }
        
    cout << mid << endl;
}

int main(){
    AC;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}