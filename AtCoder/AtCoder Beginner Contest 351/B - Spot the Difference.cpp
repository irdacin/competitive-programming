#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    char a[n][n];
    for(auto &s:a) for(auto &c:s) cin >> c;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char b; cin >> b;
            if(b!=a[i][j]) return void(cout << i+1 << ' ' << j+1);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}