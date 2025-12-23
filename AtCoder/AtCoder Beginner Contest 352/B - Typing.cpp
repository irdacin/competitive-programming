#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s, t;
    cin >> s >> t;

    for(int i=0, j=0; i<len(s) && j<len(t); j++){
        if(s[i]==t[j]) cout << j+1 << ' ', i++;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}