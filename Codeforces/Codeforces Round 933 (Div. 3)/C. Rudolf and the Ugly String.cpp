#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; string s;
    cin >> n >> s;

    int ans = 0;
    for(int i=0;i<n-2;){
        if(s[i]=='m' && s[i+1]=='a' && s[i+2]=='p') ans++, i+=3;
        else if(s[i]=='p' && s[i+1]=='i' && s[i+2]=='e') ans++, i+=3;
        else i++;
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