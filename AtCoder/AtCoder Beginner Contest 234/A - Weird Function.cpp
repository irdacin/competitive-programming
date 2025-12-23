// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int f(int x){
    return x * x + x * 2 + 3;
}

int main() {
    int t; cin >> t;
    cout << f(f(f(t) + t) + f(f(t)));
}