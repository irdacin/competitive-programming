#include <iostream>

int main() {
    int n; std::cin >> n;
    std::string ans = n%2 ? "Perlu" : "Tidak";
    std::cout << ans;
    return 0;
}