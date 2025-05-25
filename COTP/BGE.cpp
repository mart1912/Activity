#include <iostream>
    
int main() {
    int a;
    std::cin >> a;
    if (0 <= a && a <= 28) std::cout << 2;
    else if (29 <= a && a <= 52) std::cout << 3;
    else if (53 <= a && a <= 77) std::cout << 4;
    else std::cout << 5;
    return 0;
}