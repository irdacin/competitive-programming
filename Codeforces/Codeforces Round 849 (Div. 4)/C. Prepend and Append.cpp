#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;
    int cnt=0;
    for(int i=0;i<n/2;i++){
        if(s[i]=='1'&&s[n-1-i]=='1' || s[i]=='0'&&s[n-1-i]=='0') break;
        cnt++;
    }
    cout << n-cnt*2;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}