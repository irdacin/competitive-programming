#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n, a, b;
    cin >> n;

    pair<int,bool>times[n*2];
    bool cur=true;
    for(auto &[time,isArival]:times) cin >> time, isArival=cur, cur^=1;
    sort(times, times+n*2);

    int ans=0, people=0;
    for(auto &[time,isArival]:times){
        if(isArival) people++; // if arrival, people will increase
        else people--; // else people will decrease
        ans = max(people, ans);
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