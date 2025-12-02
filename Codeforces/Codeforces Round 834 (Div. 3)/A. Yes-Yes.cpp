#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    string s; cin >> s;
    string yes = "Yes";

    if(s[0]=='Y'){
        int idx=0;
        for(auto &c:s) if(c!=yes[idx++%3]) exit("NO");
    } else if(s[0]=='e'){
        int idx=1;
        for(auto &c:s) if(c!=yes[idx++%3]) exit("NO");
    } else if(s[0]=='s'){
        int idx=2;
        for(auto &c:s) if(c!=yes[idx++%3]) exit("NO");
    } else exit("NO");

    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}