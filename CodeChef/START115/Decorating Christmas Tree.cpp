#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    int big=x/2;

    if(big>=n) return void(cout << "YES");

    int small = min(x,y/3);
    x-=small;
    big=x/2;
    if(small+big>=n) return void(cout << "YES");
    cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}