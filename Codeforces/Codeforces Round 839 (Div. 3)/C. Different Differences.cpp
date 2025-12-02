#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int k, n; cin >> k >> n;

    deque<int>a;
    bool flag=false;
    for(int i=1, cur=n, j=k-1;i<=k;i++, j--){
        a.push_front(cur);

        if(flag){
            cur--;
        }
        
        else {
            cur-=i;
            if(cur+i<=0 || cur<j) cur=cur+i-1, flag=true;
        }
    }
    for(auto &i:a) cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}