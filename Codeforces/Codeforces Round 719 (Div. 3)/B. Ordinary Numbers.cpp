#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n;
    cin >> n;
    // if(n<10) return void(cout << n);

    auto power = [&](int a, int k, auto self){
        if(k==0) return (int)1;
        int res=self(a,k/2,self);
        return k&1?res*res*a:res*res;
    };

    int p = to_string(n).length()-1;

    int increment=1;
    for(int i=1;i<=p;i++) increment=increment*10+1;

    int ans=p*9;
    for(int i=increment;i<power(10,p+1,power)&&i<=n;i+=increment) ans++;
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}