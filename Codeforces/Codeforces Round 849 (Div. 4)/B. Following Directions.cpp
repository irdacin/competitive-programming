#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;
    int x=0, y=0;
    for(auto &c:s){
        if(c=='L') x--;
        else if(c=='R') x++;
        else if(c=='U') y++;
        else y--;

        if(x==1 && y==1) exit("YES");
    }
    cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}