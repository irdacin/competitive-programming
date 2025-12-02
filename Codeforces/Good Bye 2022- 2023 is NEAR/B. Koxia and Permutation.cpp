#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n, k; cin >> n >> k;

    deque<int>p;
    for(int i=1, cnt=1;i<=n;cnt++)
        if(cnt%k==0) p.push_back(i++);
        else p.push_back(n--);

    for(auto &i:p) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}