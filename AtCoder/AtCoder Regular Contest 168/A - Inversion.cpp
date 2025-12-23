#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s; cin>>s;

    // int a[n];
    // a[0]=1;
    ll cnt = 0, ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='>') cnt++, ans+=cnt;
        else cnt=0;
    }
        // a[i+1] = (s[i]=='<') ? a[i]+n : a[i]-1;
    

    
    cout << ans;
}

int main(){
    ez;
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}