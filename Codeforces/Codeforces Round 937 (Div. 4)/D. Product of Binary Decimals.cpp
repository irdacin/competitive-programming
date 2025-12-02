#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;

    auto isBinary = [&](string s){
        for(auto c:s) if(c!='0' && c!='1') return false;
        return true;
    };
    
    if(isBinary(to_string(n))) exit("YES");

    while(n>1){
        vector<int> factors;
        for(int i=1; i*i<=n; i++){
            if(n%i==0){
                factors.push_back(i);
                if(i!=n/i) factors.push_back(n/i);
            }
        }

        sort(factors.begin(), factors.end(), greater<int>());
        factors.pop_back(); // erase 1 from factors because div by 1 is always same

        bool can = false;
        for(auto factor:factors){
            if(isBinary(to_string(factor))){
                n/=factor;
                can = true;
                break;
            }
        }

        if(!can) exit("NO");
    }

    cout << "YES";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}