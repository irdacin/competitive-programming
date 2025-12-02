#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n, k; string s;
    cin >> n >> k >> s;

    auto upper = [](char c){
        return c>='A' && c<='Z';
    };

    int ans = 0;
    map<char,int> mp;
    for(auto c:s){
        mp[c]++;
        if(upper(c) && mp[tolower(c)]>0) ans++, mp[c]--, mp[tolower(c)]--;
        else if(!upper(c) && mp[toupper(c)]>0) ans++, mp[c]--, mp[toupper(c)]--;
    }

    for(auto [ch, cnt]:mp){
        // cout << ch << ' ' << cnt << endl;
        if(k>0 && cnt>=2) ans+=min(k, cnt/2), k-=cnt/2;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}