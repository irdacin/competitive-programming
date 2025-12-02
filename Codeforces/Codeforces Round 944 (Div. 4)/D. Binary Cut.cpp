#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; cin >> s;

    int ans = 1; bool first = true;
    for(int i=1; i<len(s); i++){
        if(s[i-1]=='1' && s[i]=='0') ans++;
        else if(s[i-1]=='0' && s[i]=='1'){
            if(first) first = false;
            else ans++;
        }
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