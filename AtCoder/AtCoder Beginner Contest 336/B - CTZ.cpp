#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){    
    int n; cin >> n;
    string res="";
    function<void(int)>bin = [&](int a){
        if(a>0) bin(a/2);
        res+=to_string(a%2);
    };
    bin(n);
    int ans=0;
    for(int i=res.length()-1;i>=0;i--){
        if(res[i]=='1') break;
        ans++;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}