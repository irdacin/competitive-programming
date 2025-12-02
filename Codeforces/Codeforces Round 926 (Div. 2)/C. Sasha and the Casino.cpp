#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int k, x, a; 
    cin >> k >> x >> a;

    int lost = 0;
    while(x--){
        if(lost>a) break;
        int y = (lost+k-1)/(k-1);
        // cout << y <<endl;
        lost+=y;
    }

    if((a-lost)*k > a) cout << "YES";
    else cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}