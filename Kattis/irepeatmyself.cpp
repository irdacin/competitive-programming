#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    string s; getline(cin, s);
    
    for(int i=1; i<len(s); i++){
        string current = s.substr(0, i);

        bool can = true;
        for(int j=i; j<len(s) && can; j+=i){
            string temp = s.substr(j, i);
            // cout << current << " => " << temp << endl;

            int cnt = 0;
            for(;cnt<min(len(temp), len(current)) && temp[cnt]==current[cnt]; cnt++);
            if(cnt!=min(len(temp), len(current))) can = false;
        }

        if(can) exit(len(current));
    }
    
    cout << len(s);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; 
    cin.ignore();
    while(t--)
    solve(), cout << endl;
}