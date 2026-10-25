#include <iostream>
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define ll long long
using namespace std;

ll square_root(ll a){
    if(a==0 || a==1) return a;
    
    ll left = 1, right = a/2;
    while(left<=right){
        ll mid = (left+right)/2;
        ll hasil = mid*mid;
        if(hasil==a) return mid;
        else if(hasil<a) left = mid+1;
        else right = mid-1;
    }
    return right;
}

int main(){
    ez
    int n;
    cin >> n;
    
    while(n--){
        ll posisi; cin >> posisi;
        ll akar = square_root(posisi);
        cout << akar << "^2 = " << akar*akar << endl;
    }
    return 0;
}