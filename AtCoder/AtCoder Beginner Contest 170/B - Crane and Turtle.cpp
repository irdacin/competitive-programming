#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int x, y; cin >> x >> y;

    for(int crane=0; crane<=x;crane++){
        int turtle = x-crane;
            if(crane*2+turtle*4==y) exit("Yes");
    }
    cout << "No";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}