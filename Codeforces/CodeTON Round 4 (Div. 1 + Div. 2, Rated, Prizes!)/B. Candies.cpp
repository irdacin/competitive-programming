#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int n; cin >> n;
    if(n%2==0) exit(-1);

    deque<int>ans;
    function<void(int)> func = [&](int n){
        if(n==1) return;

        // two ways to find x

        // spell 1
        // 2x-1 = n
        // x = (n+1)/2

        // spell 2
        // 2x+1 = n
        // x = (n-1)/2

        int spell1 = (n+1)/2;
        int spell2 = (n-1)/2;

        if(spell1&1){
            ans.push_front(1);
            func(spell1);
        } else if(spell2&1){
            ans.push_front(2);
            func(spell2);
        } else return;

    };

    func(n);
    cout << ans.size() << endl;
    for(auto &i:ans) cout << i << ' '; 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}