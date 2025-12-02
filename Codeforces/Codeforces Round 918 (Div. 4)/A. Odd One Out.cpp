#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int a[3];
    map<int, int>mp;
    for(auto &i:a) cin >> i, mp[i]++;
    
    int dif=-1;
    for(auto &[value, cnt]:mp) if(cnt==1) dif=value;
    cout << dif;
}   

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}