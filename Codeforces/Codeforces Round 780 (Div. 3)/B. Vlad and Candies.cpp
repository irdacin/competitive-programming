#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    sort(a,a+n);
    if(a[n-1]==1 || n!=1&&a[n-1]-a[n-2]==1 || n!=1&&a[n-1]-a[n-2]==0) cout << "YES";
    else cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}