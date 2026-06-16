#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define exit(x) return void(cout << x)
#define len(x) (int) x.size()
using namespace std;

void solve(double a1, double b1, double c1, double a2, double b2, double c2){
    if(a1==a2 && b1==b2) exit("No fixed point exists.");

    // case 
    // 2x + 2y = 8 x2
    // 4x + 4y = 8 x1

    // 4x + 4y = 16
    // 4x + 4y = 8

    // if(a1==b1 && a2==b2) exit("No fixed point exists.");

    double tmp_a1 = a1, tmp_b1 = b1, tmp_c1 = c1, tmp_a2 = a2, tmp_b2 = b2, tmp_c2 = c2;

    // test case
    // 10 2 3
    // 14 7 5

    // to avoid floating point, we calculate with elemination x and y

    // eliminate x
    // 10x + 2y = 3 x14
    // 14x + 7y = 5 x10

    if(a1 != a2){
        double tmp1 = a1, tmp2 = a2;
        a1*=tmp2, a2*=tmp1;
        b1*=tmp2, b2*=tmp1;
        c1*=tmp2, c2*=tmp1;
    }
    
    
    if(b1 == b2) exit("No fixed point exists.");


    // 140x + 28y = 42
    // 140x + 70y = 50

    // y = (42 - 50) / (28 - 70)
    double y = (c1 - c2) / (b1 - b2);

    // restore the value
    a1 = tmp_a1, a2 = tmp_a2, b1 = tmp_b1, b2 = tmp_b2, c1 = tmp_c1, c2 = tmp_c2;


    // eliminate y
    // 10x + 2y = 3 x7
    // 14x + 7y = 5 x2

    if(b1 != b2){
        double tmp1 = b1, tmp2 = b2;
        a1*=tmp2, a2*=tmp1;
        b1*=tmp2, b2*=tmp1;
        c1*=tmp2, c2*=tmp1;
    }

    // 70x + 14y = 21
    // 28x + 14y = 10

    // x = (21 - 10) / (70 - 28)
    double x = (c1 - c2) / (a1 - a2);


    cout << "The fixed point is at " << setprecision(2) << fixed << x << ' ' << y << '.';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int t; cin >> t; while(t--)
    for(double a1,b1,c1,a2,b2,c2; cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;)
    if( !(a1==0 && b1==0 && c1==0 && a2==0 && b2==0 && c2==0) )
    solve(a1,b1,c1,a2,b2,c2), cout << endl;
}