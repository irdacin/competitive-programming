#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    int sum=0;
    for(auto &i:a) sum+=i;
    if(sum%3==0) exit(0);
    if(sum%3==2) exit(1);

    for(auto &i:a){
        int cur = sum-i;
        if(cur%3==0) exit(1);
    }

    cout << 2;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}