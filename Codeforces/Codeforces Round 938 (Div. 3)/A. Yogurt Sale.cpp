#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;

    int price = min(2*a, b);
    if(n%2==0) cout << price*n/2;
    else cout << price*(n-1)/2 + a;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}