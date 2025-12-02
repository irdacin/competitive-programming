#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n,x;
    cin>>n>>x;
    int a[n]; 
    for(auto &i:a) cin >> i;
    
    int current=0, ans=-1;
    for(auto &i:a){
        ans = max(ans, abs(current-i));
        current = i;
    }
    ans = max(ans, abs(current-x)*2);
    cout << ans << endl;
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}