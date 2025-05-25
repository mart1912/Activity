#include <iostream>
    
int main() {
    int p, k;
    std::cin >> p >> k;
    //p = 2 * (a + b) = 2 * (a + k * a) = 2 * a * (k + 1)
    int a = p / (2 * (k + 1));
    std::cout << k * a * a;
    return 0;
}