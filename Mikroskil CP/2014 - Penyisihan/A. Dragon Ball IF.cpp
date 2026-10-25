#include <iostream>
using namespace std;

string repeat(char s, int time){
    string ulang = "";
    for(int i=0;i<time;i++){
        ulang+=s; 
    }
    return ulang;
}

int main(){
    int n, p;
    cin >> n;
    string word = "kamehameha";

    while(n--){
        cin >> p;
        for(int i=0;i<word.length();i++){
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u'){
                cout << repeat(word[i],p);
            } else{
                cout << word[i];
            }
        }
        cout << endl;
    }
    return 0;
}