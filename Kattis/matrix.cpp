#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(int a, int b, int c, int d){
    int det = a*d-b*c;
    cout << d/det << ' ';
    cout << -b/det << endl;
    cout << -c/det << ' ';
    cout << a/det << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(int a, b, c, d, tc=1; cin >> a >> b >> c >> d; tc++)
    cout << "Case " << tc << ':' << endl,
    solve(a,b,c,d);
}