#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(auto &i:a) cin >> i;

    int prev = 0;
    for(auto i:a){

        // if(i>=prev){
        //     prev = i%10;
        //     continue;
        // }

        if(i<10){
            if(i < prev) exit("NO");
            prev = i;
            continue;
        }
        int num2 = i%10;
        int num1 = i/10;

        // if(num1 > num2 || num2 < prev) exit("NO");
        if(num1 > num2){
            if(i < prev) exit("NO");
            else prev = i;
        } else if(num1 < prev){
            if(i < prev) exit("NO");
            else prev = i;
        }
            else  prev = num2;


        // cout << prev << endl;
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