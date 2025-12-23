// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> v;
    for(int i = 0, a; i < n - k; i++) cin >> a, v.emplace_back(a);
    for(int i = 0, a; i < k; i++) cin >> a, cout << a << ' ';
    for(auto i : v) cout << i << ' ';
}