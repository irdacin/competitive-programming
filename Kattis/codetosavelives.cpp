#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string n, m;
    getline(cin >> ws, n);
    getline(cin >> ws, m);

    int num1 = 0;
    for(auto &c:n){
        if(c==' ') continue;
        num1 = num1*10 + (c-'0');
    }

    int num2 = 0;
    for(auto &c:m){
        if(c==' ') continue;
        num2 = num2*10 + (c-'0');
    }

    int res = num1+num2;
    for(auto c:to_string(res)) cout << c << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}