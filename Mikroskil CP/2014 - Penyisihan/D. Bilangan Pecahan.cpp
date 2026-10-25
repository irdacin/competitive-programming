#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main() {
    int a,b;
    cin >> a >> b;
    
    int fpb = gcd(a,b);
    if(fpb!=1) cout << a/fpb << " " << b/fpb;
    else cout << "Tidak";
    cout << endl;
    return 0;
}