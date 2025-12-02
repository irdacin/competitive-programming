#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    string s, t; cin >> s >> t;
    string a = "";
    a+=s[0];
    for(int i=1;i<n;i++){
        if(s[i-1]==s[i]){
            a+=t;
        }
        
        a+=s[i];
    }
    char curr=a[0];
    for(int i=1;i<a.length();i++)
    if(curr==a[i]){
        cout << "No" << endl;
        return;
    } else curr=a[i];
    cout << "Yes" << endl;
    
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}