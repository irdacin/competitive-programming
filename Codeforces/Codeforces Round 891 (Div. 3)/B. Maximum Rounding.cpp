#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

void solve(){
    string x;
    cin >> x;
    x = '0'+x;

    int n = x.length();

    int k = x.length(), i=n-1;
    for(;i>=0;i--){
        if(x[i]>='5' && i>=0 && x[i-1]!='9') x[i-1]++, k=i;
    }
    if(x[++i]=='0') i++;
    for(;i<k;i++) cout << x[i];
    for(;i<n;i++) cout << 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}