#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    pair<int,int> monsters[n];
    for(auto &[a,x]:monsters) cin >> a;
    for(auto &[a,x]:monsters) cin >> x;
    
    map<int, int> mp;
    for(auto &[a,x]:monsters) mp[abs(x)]+=a;

    int curK = k;
    for(int time=1; time<=n; time++){
        curK-=mp[time];
        if(curK < 0) exit("NO");
        
        curK+=k;
    }

    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}