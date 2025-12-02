#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; string a,b,c;
    cin >> n >> a >> b >> c;

    int dif = 0;
    for(int i=0;i<n;i++){
        // if(a[i]=b[i]) continue;
        if(a[i]==c[i] || b[i]==c[i]) dif++;
        if(dif==n) exit("NO");
    }

    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}