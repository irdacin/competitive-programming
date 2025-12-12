#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, x; 
    cin >> n >> x;
    char s[n];
    for(auto &c:s) cin >> c;
    
    int cur=0;
    for(auto &c:s){
        if(c=='0') cur--;
        else cur = x;
        if(cur<0) exit("NO");
    }
    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}