#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    char a[6];
    for(auto &c:a) cin >> c;
    
    for(int i=0;i<6-2;i++){
        if(a[i]=='W'){
            bool flag=true;
            
            for(int j=i+1;j<=i+2&&flag;j++){
                if(a[j]!='W') flag=false;
            }
            if(flag) exit("YES");
        }
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