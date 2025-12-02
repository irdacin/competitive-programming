#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    string ans="aaa";
    n-=3;
    for(int i=2;n!=0&&i>=0;i--){
        int need=min((int)25, n);
        // cout << need;
        ans[i]=(char)(ans[i]-'a'+need+'a');
        n-=need;
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