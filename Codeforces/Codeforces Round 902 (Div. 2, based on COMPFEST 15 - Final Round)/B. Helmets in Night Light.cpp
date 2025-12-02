#include <bits/stdc++.h>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define ll long long
using namespace std;

void solve(){
    int n, p; cin >> n >> p;
    int a[n], b[n];
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    pair <int, int> resident[n];
    int index=0;
    for(auto &r:resident)
    r.first = b[index], r.second = a[index++];

    sort(resident, resident+n);

    ll ans=p;
    
    for(int i=0, cnt=0;cnt<n-1;cnt++){
        if(!resident[i].second) 
        i++;

        if(resident[i].first>p){
            ans+=p; continue;
        }

        resident[i].second--;
        ans+=resident[i].first;

        // cout << resident[i].first << ' ' << resident[i].second << endl;
        
        

    }

    cout << ans << endl;   
}

int main(){
    ez;
    int t; cin >> t; while(t--)
    solve();
    return 0;
}