#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    for(int i=1;i<n-1;i++){
        a[i]-= a[i-1]*2;
        a[i+1]-=a[i-1];
        a[i-1] = 0;
        if(a[i]<0) exit("NO");
        if(a[i+1]<0) exit("NO");
    }

    for(auto i:a) if(i!=0) exit("NO");

    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}