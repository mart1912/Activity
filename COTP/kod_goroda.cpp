#include <iostream>
    
int main() {
    int a;
    std::cin >> a;
    std::cout << a / 10000000 % 10 << a / 1000000 % 10 << a / 100000 % 10;
}