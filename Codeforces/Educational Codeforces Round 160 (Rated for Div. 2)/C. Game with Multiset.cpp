#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int m; cin >> m;

    function<int(int)>power=[&](int k){
        if(k==0) return (int) 1;
        int res = power(k/2) ;
        return (k%2) ? res*res*2:res*res;
    };

    // multiset<int, greater<int>>pref={0};
	map<int, int> mp;
    while(m--){
        int t, v;
        cin >> t >> v;
        if(t==1) mp[power(v)]++;
		else {
			for(auto it=mp.rbegin();it!=mp.rend();++it){
				auto [num, times] = *it;
				int d=min(v/num, times);
				v-=d*num;
				if(v==0) break;
			}
			cout << (v==0 ? "YES":"NO") << endl;
		}

    }

	// for(auto &i:mp)
	// 	cout << i.first << ' ' << i.second << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve();
}