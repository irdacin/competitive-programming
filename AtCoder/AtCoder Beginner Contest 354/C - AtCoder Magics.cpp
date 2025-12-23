#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    tuple<int,int,int> cards[n];
    for(int idx=1; auto &[a,c,i]:cards) i=idx++, cin >> a >> c;
    sort(cards, cards+n, [](auto fi, auto se){
        auto [a1,c1,i1] = fi;
        auto [a2,c2,i2] = se;
        return a1 > a2;
    });

    int mn = INT_MAX;
    set<int> discard;
    for(auto [a,c,idx]:cards){
        if(c < mn) {
            mn = c;
            discard.insert(idx);
        }
    }

    cout << len(discard) << endl;
    for(auto i:discard)  cout << i << ' ';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}