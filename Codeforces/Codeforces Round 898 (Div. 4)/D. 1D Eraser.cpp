#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    int count=0;
    for(int i=0;i<s.length();i++)
    if(s[i]=='B') 
        {i+=(k-1);count++;continue;
    }
    cout << count << endl;
}   

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}