#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(int n){
    if(n==0) return;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int a; n--;) cin >> a, pq.push(a);

    int ans = 0;
    while(len(pq)>1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        ans += (a+b);
        pq.push(a+b);
    }
    cout << ans;
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(int n; cin >> n;)
    solve(n);
}