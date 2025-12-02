#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    
    // gcd 4 and 6 = 2
    if(n%2!=0 || n<4) exit(-1);

    cout << n/6 + (n%6==0?0:1) << ' ' << n/4;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}