#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
using namespace std;

void solve(){
    int m, s;
    cin >> m >> s;
    int a[m];
    for(auto &i:a) cin >> i;

    // deret aritmatika
    // Sn = Un/2 * (a+Un) // a disini 1

    int un=0;
    for(auto &i:a) if(i>un) un=i;
    int sum = un*(1+un)/2;
    for(auto &i:a) sum-=i;
    s-=sum;
    
    if(s==0) exit("YES");
    for(int num=un+1;s>-1;s-=num,num++) if(s-num==0) exit("YES");
    cout << "NO";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while(t--)
    solve(), cout << endl;
}