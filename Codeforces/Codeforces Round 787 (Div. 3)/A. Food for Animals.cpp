#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    a-=x; b-=y;
    if(a>=0 && b>=0) exit("YES");

    int need = 0;
    if(a<0) need+=-a;
    if(b<0) need+=-b;
    cout << (c>=need ? "YES":"NO");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}