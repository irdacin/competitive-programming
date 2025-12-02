#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    int b[n+2];
    for(auto &i:b) cin >> i;

    sort(b,b+n+2);
    int sum=0;

    int a[n];
    for(int i=0;i<n;i++) a[i]=b[i], sum+=a[i];

    if(sum!=b[n]){
        sum+=b[n];
        int idx = -1;
        for(int i=0;i<n+1;i++) if(sum-b[i]==b[n+1]) idx = i;
        if(idx==-1) exit(-1);
        a[idx] = b[n];
    }

    for(auto &i:a) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}