#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; string s; 
    cin >> n >> s;

    int pref[2][n+1];
    pref[0][0] = 0;
    pref[1][0] = 0;

    set<char>temp;
    for(int i=1;i<=n;i++){
        temp.insert(s[i-1]);
        pref[0][i]=temp.size();
    }
    temp.clear();
    for(int i=1;i<=n;i++){
        temp.insert(s[n-i]);
        pref[1][i]=temp.size();
    }
    
    // for(auto &i:pref) for(auto &a:i) cout << a << ' ';  
    int ans=0;
    for(int i=1;i<n;i++){
        ans = max(ans, pref[0][i]+pref[1][n-i]);
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