#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a>b) swap(a,b);

    int cnt = 0;
    for(int i=a; i<b; i++){
        if(i==c || i==d) cnt++;
    }

    if(cnt==1) cout << "YES";
    else cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}