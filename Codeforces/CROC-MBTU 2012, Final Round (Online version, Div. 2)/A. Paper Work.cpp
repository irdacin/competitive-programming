#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int cek = 0,indeks = 0,folder = 1;
    vector <int> index;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            if(cek>1){
                cek = 1;
                folder++;
                index.push_back(indeks);
                indeks = 1;
                continue;
            }else{
                cek++;
            }
        }
        indeks++;
    }
    cout<<folder<<endl;
    for(auto i:index) cout <<i<<" "; 
    cout<<indeks;
    return 0;
}