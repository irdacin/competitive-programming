#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; cin >> s;
    
    string st = "";
    int cnt1 = 0, cnt2 = 0;
    for(auto c:s){
        if(c=='<') cnt1++;
        else if(c=='>') cnt2++;

        bool flag = true;
        for(auto ch:st){
            if(ch==c){
                flag=false;
                break;
            }
        }

        if(cnt1>1 || cnt2 > 1) exit("No");
        if(flag) st+=c;

    }

    if(st=="<=>") cout << "Yes";
    else cout << "No";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}