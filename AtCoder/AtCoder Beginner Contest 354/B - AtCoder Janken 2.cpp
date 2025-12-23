#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    pair<string, int> users[n];
    int sum = 0;
    for(auto &[s,c]:users) cin >> s >> c, sum+=c;
    sort(users,users+n);

    int score = sum % n;
    for(int idx = 0;auto [s,c]:users) if(idx==score) exit(s); else idx++;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}