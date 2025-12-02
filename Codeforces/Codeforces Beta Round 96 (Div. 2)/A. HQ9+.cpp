#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    string p;
    cin >> p;
    for(int i=0;i<p.length();i++){
        if(p[i]=='H' || p[i]=='Q' || p[i]=='9'){
            cout << "YES";
            return;
        }
    }    
    cout << "NO";
}

int main(){
    AC;
    // int t; cin >> t; while(t--)
    solve();
    return 0;
}