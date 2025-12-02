#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    pair<int, int> one, two;
    auto &[l1, r1] = one;
    auto &[l2, r2] = two;
    cin >> l1 >> r1 >> l2 >> r2;
    if(one>two) swap(one, two);

    if(l1<=l2 && l2<=r1) cout << l2;
    else cout << l1+l2;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}