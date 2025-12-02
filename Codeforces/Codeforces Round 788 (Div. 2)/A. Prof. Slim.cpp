#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    int cnt = 0;
    for(auto &i:a){
        cin >> i;
        if(i<0) i*=-1, cnt++;
    }

    int i = 0;
    for(; i<cnt; i++){
        if(i<cnt-1 && a[i] < a[i+1]) exit("NO");
    }
    for(; i<n; i++){
        if(i<n-1 && a[i] > a[i+1]) exit("NO");
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