#include <iostream>
#include <print>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int w; cin >> w;
    if(w & 1 || w == 2) print("NO");
    else print("YES");
    return 0;
}