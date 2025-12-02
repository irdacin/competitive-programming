#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    map<char,int>mp;
    for(char i='a';i<='z';i++) mp[i] = 0;

    string ans="";
    for(auto &i:a){
        for(auto &[chr,cnt]:mp){
            if(cnt==i){
                ans+=chr, cnt++;
                break;
            }
        }
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