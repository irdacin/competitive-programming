#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; cin >> s;

    if(s[0]=='0'){
        if(s[1]=='0') cout << 12;
        else cout << s.substr(0,2);
        cout << s.substr(2,len(s)-2) << " AM";
    } else {
        int hour = (s[0]-'0') * 10 + (s[1]-'0');
        if(hour < 12) cout << s << " AM";
        else if(hour==12) cout << s << " PM";
        else {
            hour-=12;
            if(hour<10) cout << 0;
            cout << hour;
            cout << s.substr(2,len(s)-2) << " PM";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}