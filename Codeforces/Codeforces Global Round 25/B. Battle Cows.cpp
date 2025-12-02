#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k; cin >> n >> k; k--;
    int a[n];
    for(auto &i:a) cin >> i;

    int pos = k;
    for(int i=0; i<n; i++){
        if(a[i]>a[k]){
            pos = i;
            break;
        }
    }
    // cout << pos;

    // win all game
    if(pos==k) exit(n-1);

    int win = 0;
    for(int i=1; i<pos; i++){
        if(a[i]>a[k]) break;
        win++;
    }

    int win2 = 0;
    for(int i=pos+1; i<k; i++){
        if(a[i]>a[k]) break;
        win2++;
    }
    if(pos>0 && pos<k) win2++;

    // cout << win << ' ' << win2;
    cout << max(win, win2);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}