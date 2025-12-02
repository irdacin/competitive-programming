#include <iostream>
using namespace std;

unsigned long long dollar1(unsigned long long x,unsigned  long long y,unsigned  long long a, unsigned long long b){
    if(x>y){
        unsigned long long z=x;
        x=y;
        y=z;
    }
    
    unsigned long long dollar = 0; 
    if(x>0 && y>0){
        dollar+=x*b;
        y-=x;
    }
    if(y>0){
        dollar+=y*a;
    }
    return dollar;
}

unsigned long long dollar2(unsigned long long x,unsigned long long y,unsigned long long a,unsigned long long b){
    unsigned long long dollar = 0;
    if(x>0){
        dollar+=a*x;
    }
    if(y>0){
        dollar+=a*y;
    }
    return dollar;
}

int main(){
    unsigned long long t,x,y,a,b;
    cin>>t;
    while(t--){
        cin>>x>>y>>a>>b;
        cout<<min(dollar1(x,y,a,b),dollar2(x,y,a,b))<<endl;
    }
    return 0;
}