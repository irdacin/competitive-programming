#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;

    for(int i=0;i<n; i++){
        int j=i+1;
        for(;j<n && s[j]!=s[i];j++);

        cout << s[i];
        i = j;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}