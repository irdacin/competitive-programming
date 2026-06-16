#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int wall[n];
    for(auto &i:wall) cin >> i;

    int prev = wall[0];
    int high=0, low=0;
    for(auto &i:wall){
        if(i>prev) high++;
        else if(i<prev) low++;
        prev = i;
    }

    cout << high << ' ' << low;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 0;
    int t; cin >> t; while(t--)
    cout << "Case " << ++tc << ": ",
    solve(), cout << endl;
}