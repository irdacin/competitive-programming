#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    int idx=0;
    for(auto &i:a) cin >> i, i-=idx++;
    
    // aj-ai=j-i => aj-j-ai-i
    map<int,int> mp;
    int ans=0;
    for(auto &i:a) ans+=mp[i], mp[i]++;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}