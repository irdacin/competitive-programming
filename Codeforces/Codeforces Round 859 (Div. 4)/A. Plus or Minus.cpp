#include <iostream>
using namespace std;

int main(){
    int t,a,b,c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(a+b==c) cout << "+";
        else cout << "-";
        cout << endl;
    }
    return 0;
}