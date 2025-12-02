#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; string s; 
    cin >> n >> s;

    int ans = 0; char prev = '.';
    for(auto c:s){
        if(c=='@') ans++;
        else if(c=='*' && prev=='*') break; 
        prev = c;
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