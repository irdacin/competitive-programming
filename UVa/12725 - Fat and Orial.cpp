#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(){
    double n, m, a, b;
    cin >> n >> m >> a >> b;

    // n*a + b*? = m*(a+b)
    // ? = (m*(a+b) - n*a) / b

    double grade = (m*(a+b) - n*a) / b;
    if(grade<0 || grade>10) exit("IMPOSSIBLE");

    cout << setprecision(2) << fixed;
    cout << grade;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; for(int tc=1;t--;)
    cout << "Case #" << tc++ << ": ",
    solve(), cout << endl;
}