#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, m, a;
    cin >> n >> m >> a;
    // int ans=m*n/a/a;
    int p=n/a;
    if(n%a!=0) p++;

    int l=m/a;
    if(m%a!=0) l++;
    cout << p*l;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}