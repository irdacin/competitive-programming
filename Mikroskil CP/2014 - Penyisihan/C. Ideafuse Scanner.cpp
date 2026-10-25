#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    
    string word = "ideafuse";
    int ketemu = s.find(word)!=-1 ? s.find(word)+1 : s.find(word);
    cout << ketemu;
     return 0;
}