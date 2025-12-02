#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.length();
    
    // check all letter is uppercase
    int cnt=0;
    for(auto &c:s) if(c>='A' && c<='Z') cnt++;
    if(cnt==n){
        for(auto &c:s) cout << (char) tolower(c);
        return;
    }

    // if(s[0]>='a' && s[0]<='z'){
        for(int i=1;i<n;i++)
            if(s[i]>='a'&&s[i]<='z') exit(s);
    // } 

    cout << (char) toupper(s[0]);
    for(int i=1;i<n;i++) cout << (char) tolower(s[i]);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}