#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int res=lcm(a,b);
    if(res==b) res*=(b%a!=0?res:b/a);
    cout << res;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}