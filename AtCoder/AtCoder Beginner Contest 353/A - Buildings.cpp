#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int h[n];
    for(int i=0; i<n; i++) cin >> h[i];

    for(int i=1; i<n; i++){
        if(h[0] < h[i]) exit(i+1);
    }
    cout << -1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}