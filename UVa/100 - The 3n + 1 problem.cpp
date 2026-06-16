#include <iostream>
using namespace std;

int cycle_size(int n){
    int cycle = 1;
    while(n!=1){
        if(n%2!=0){
            n=3*n+1;
        }else{
            n=n/2;
        }
        cycle++;
    }
    return cycle;
}

int max_cycle(int a, int b){
    if(a>b){
        int c = a;
        a = b;
        b = c;
    }

    int max = 0;
    while(a<=b){
        int cycle_number = cycle_size(a);
        if(max < cycle_number){
            max = cycle_number;
        }
        a++;
    }
    return max;
}

int main()
{
    int i,j;
    while(cin>>i>>j){
        cout<<i<<" "<<j<<" "<<max_cycle(i,j)<<endl; 
    }
    return 0;
}
