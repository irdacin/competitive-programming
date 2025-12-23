#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, m; string s;
    cin >> n >> m >> s;

    int plain=m, logo=0, tmp=0;
    for(auto &c:s){
        if(c=='1'){
            if(plain) plain--;
            else if(tmp) tmp--;
            else logo++;
        } else if(c=='2'){
            if(tmp) tmp--;
            else logo++;
        } else plain=m, tmp=logo;
    }
    cout << logo;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}