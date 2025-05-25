#include <iostream>
int main() {
    int a, b;
    std::cin >> a >> b;
    int c = abs(a - b);
    int maxx, minn;
    if (a > b) maxx = a, minn = b;
    else maxx = b, minn = a;
    int d = (7 - maxx) + minn;
    if (c > d) std::cout << d << " " << c;
    else std::cout << c << " " << d;
}