#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    int a[2*n];
    for(auto &i:a) cin >> i;
    sort(a,a+2*n);

    for(int i=0,j=n;i<n;i++,j++) if(a[j]-a[i]<x) exit("NO");
    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}