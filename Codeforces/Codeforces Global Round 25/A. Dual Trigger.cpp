#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    char s[n]; 
    int turnedOn = 0;
    for(auto &c:s) cin >> c, turnedOn+=(c=='1');

    if(turnedOn&1) exit("NO");

    int turnedOnAdjacent = 0;
    for(int i=0; i<n-1; i++){
        if(s[i]=='1' && s[i+1]=='1') turnedOnAdjacent++, i++;
    }
    cout << (turnedOn==2 && turnedOnAdjacent==1 ? "NO":"YES");
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}