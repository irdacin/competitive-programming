#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    string s; cin >> s;
    if(s[0]>='a'&&s[0]<='z') exit("No");
    for(int i=1;i<s.length();i++) if(s[i]>='A'&&s[i]<='Z') exit("No");
    cout << "Yes";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}