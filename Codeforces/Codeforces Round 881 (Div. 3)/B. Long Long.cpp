#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    int sum=0, count=0;
    bool neg=false;
    for(auto &i:a){
        sum+=abs(i);
        if(i<0) neg=true;
        else if(neg&&i>0) neg=false, count++;
    }
    if(neg) count++;
    cout << sum << ' ' << count;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}