#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;

    string temp="";
    temp+=s[0];
    for(int i=1;i<n;i++) if(s[i]!=s[i-1]) temp+=s[i];
    // cout << temp;

    set<char>res;
    for(auto &c:temp) res.insert(c);
    cout << (res.size()==temp.size() ? "YES":"NO");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}