#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    map<int,int>mp;
    for(int i=0,b;i<n*(n-1)/2;i++) cin >> b, mp[b]++;

    int a[n];
    int i=0;
    for(auto &[value, cnt]:mp){
        while(cnt>0) cnt-=n-i-1, a[i++] = value;
    }
    a[i] = a[i-1];
    for(auto &i:a) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}