#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int takahashi=0, aoki=0, x,y;
    while(n--) cin >> x >> y, takahashi+=x, aoki+=y;
    cout << (takahashi>aoki ? "Takahashi": takahashi<aoki ? "Aoki": "Draw");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}