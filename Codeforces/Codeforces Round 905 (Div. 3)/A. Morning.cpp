#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; cin >> s;

    int ans = 0;
    char cur = '1';
    for(auto c:s){
        if(c==cur) ans++;
        else if(c=='0') ans+=abs(10-(cur-'0'))+1;
        else if(cur=='0') ans+=abs((c-'0')-10)+1;
        else ans+=abs((c-'0')-(cur-'0'))+1;
        cur = c;
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