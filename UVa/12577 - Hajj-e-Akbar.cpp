#include <iostream>
using namespace std;

int main()
{
    string x;
    int n = 1;
    while(cin>>x){
        if(x=="Hajj"){
            cout << "Case " << n << ": Hajj-e-Akbar" << endl;
        }else if(x=="Umrah"){
            cout << "Case " << n << ": Hajj-e-Asghar" << endl;
        }else{
            continue;
        }
        n++;
    }
    return 0;
}
