#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()

#define vi vector<int>
#define vvi vector<vi>

const int MOD = 1e9 + 7;

void solve(){
    int n, m; cin >> n >> m;
    vi a(n), c;
    for(auto &i:a) cin >> i, c.push_back(i);
    for(int b; m--; ) cin >> b, c.push_back(b);
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    int cnt = 0;
    for(int i=0, j=0; j<len(c); j++){
        if(a[i]==c[j]) cnt++, i++;
        else cnt = 0;
        if(cnt==2) exit("Yes");
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