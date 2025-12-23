#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int w, b; cin >> w >> b;

    string s = "wbwbwwbwbwbw";
    
    for(int i=0;i<len(s); i++){
        int cntW = 0, cntB = 0;
        for(int j=i; cntW<w || cntB<b; j++, j%=len(s)){
            if(s[j]=='w') cntW++;
            else cntB++;
        }
        
        // cout << cntW << ' ' << cntB << endl;
        if(cntW==w && cntB==b) exit("Yes");

    }

    cout << "No";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    solve(), cout << endl;
}