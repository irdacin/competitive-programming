#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int n = a+b, cnt=0;
    char s[n];
    for(auto &c:s){
        cin >> c;
        if(c=='0') a--, cnt++;
        else if(c=='1') b--, cnt++;
    }

    if(a<0) exit(-1);
    if(b<0) exit(-1);

    if(cnt==n){
        for(int i=0;i<n/2;i++)
            if(s[i]!=s[n-i-1]) exit(-1);
    }

    for(int i=0;i<n/2;i++){
        // cout << s[i] << ' ' << s[n-i-1] << endl;

        if(s[i]=='?'&&s[n-i-1]=='?') continue; // do last
        
        if(s[i]=='?'){
            if(s[n-i-1]=='0') a--, s[i]='0';
            else b--, s[i]='1';
        }
        else if(s[n-i-1]=='?'){
            if(s[i]=='0') a--, s[n-i-1]='0';
            else b--, s[n-i-1]='1';
        }
        if(a<0) exit(-1);
        if(b<0) exit(-1);
    }

    for(int i=0;i<n/2;i++){
        if(s[i]=='?' && s[n-i-1]=='?'){
            if(a>b) s[i]='0', s[n-i-1]='0', a-=2;
            else s[i]='1', s[n-i-1]='1', b-=2;
        }
        if(a<0) exit(-1);
        if(b<0) exit(-1);
    }

    if(n%2==1 && s[n/2]=='?'){
        if(a==1) s[n/2]='0';
        else if(b==1) s[n/2]='1';
        else exit(-1);
    }

    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-i-1]) exit(-1);

    for(auto &c:s) cout << c;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}