#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    int total_money = 0;
    while(t--){
        string x;
        int k;
        cin>>x;
        if(x=="donate"){
            cin>>k;
            total_money+=k;
        }else{
            cout<<total_money<<endl;
        }
    }
    return 0;
}
