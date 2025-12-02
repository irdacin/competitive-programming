#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int odd = n/2+n%2,
    even = n/2;
    
    if(k<=odd) cout << 2*(k-1)+1;
    else cout << 2*(k-odd);

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}