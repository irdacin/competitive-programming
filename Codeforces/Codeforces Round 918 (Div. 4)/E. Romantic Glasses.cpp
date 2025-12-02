#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    int sumOdd=0, sumEven = 0;
    map<int, int>mp;
    for(int i=0;i<n;i++){
        if(i&1) sumOdd+=a[i];
        else sumEven+=a[i];

        int dif=sumEven-sumOdd;
        
        if(dif==0||mp.find(dif)!=mp.end()) return void(cout<<"YES");
        mp[dif]=i;


    }

    cout << "NO";
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}