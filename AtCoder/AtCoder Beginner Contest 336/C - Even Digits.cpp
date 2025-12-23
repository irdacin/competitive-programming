#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){    
    int n; cin >> n;

    string res="";
    function<void(int)>bin=[&](int a){
        if(a) bin(a/5);
        res+=to_string(a%5);
    };
    bin(n-1);
    cout << stoll(res)*2;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}