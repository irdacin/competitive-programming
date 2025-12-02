#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;
    
    map<char,vector<int>>mp;
    for(int i=0;i<n;i++) mp[s[i]].push_back(i);

    for(auto &[ch,vec]:mp){
        int cur=vec[0]%2;
        for(auto &i:vec){
            if(i%2!=cur) exit("NO");
            cur=i%2;
        }
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