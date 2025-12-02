#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; cin >> s;

    int i=0;
    for(; i<len(s); i++){
        if(i>0 && s[i]!=s[i-1]) break;
    }
    if(i==len(s)) exit("NO");

    cout << "YES" << endl;
    swap(s[0], s[i]);
    cout << s;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}