#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    const string phi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    int n;
    cin>>n;
    cout << "3.";
    for(int i=2;i<n+2;i++) cout << phi[i];
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}