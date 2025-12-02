#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    auto v = [](char a){
        return a=='a'|| a=='e';
    };

    auto c = [](char a){
        return a=='b'|| a=='c' || a=='d';
    };

    string temp="";
    for(int i=0;i<n;i++){
        if(i!=0 && c(s[i])&&c(s[i-1])) temp+='.';
        temp+=s[i];
    }

    n = temp.length();
    string cur="";
    for(int i=0;i<n;i++){
        if(i!=0 && v(temp[i-1])&&c(temp[i])) cur+='.';
        cur+=temp[i];
    }

    n = cur.length();
    string ans="";
    for(int i=0;i<n;i++){
        if(i<n-2&&cur[i]=='.'&&cur[i+2]=='.') continue;
        if(i>=n-2&&cur[i]=='.') continue;
        ans+=cur[i];
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