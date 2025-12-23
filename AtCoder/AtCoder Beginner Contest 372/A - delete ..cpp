// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    for(auto c : s) if(c != '.') cout << c;
}