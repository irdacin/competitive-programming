#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

const int MAXN = 1e6+1;
bool prime[MAXN+1];

void sieve(){
    memset(prime, true, sizeof(prime));

    for(int p=2; p*p<=MAXN; p++){
        if(prime[p]){
            for(int i=p*p; i<=MAXN; i+=p)
                prime[i] = false;
        }
    }
}

void solve(){
    int x; cin >> x;

    // auto prime = [](int x){
    //     if(x<2) return false;
    //     for(int i=2;i*i<=x;i++) if(x%i==0) return false;
    //     return true;
    // };
    if(x==1) exit("NO");

    auto sqrt = [](int x){
        int res = x;
        for(int left=0, right=min((int)1e6+1, x);left<=right;){
            int mid = left+(right-left)/2;
            if(mid*mid<=x) res = mid, left=mid+1;
            else right=mid-1;
        }

        return res;
    };
    
    if(sqrt(x)*sqrt(x)==x){    
        if(prime[sqrt(x)]) cout << "YES";
        else cout << "NO";
    }
    else cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();
    
    int t; cin >> t; while(t--)
    solve(), cout << endl;
}