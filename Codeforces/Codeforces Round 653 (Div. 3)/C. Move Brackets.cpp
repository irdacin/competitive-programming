#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    char s[n];
    for(auto &c:s) cin >> c;

    int left=0, right=0;
    for(auto &c:s){
        if(c==')' && !left) right++;
        else if(c=='(') left++;
        else left--;
    }
    cout << right;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}