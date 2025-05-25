#include <iostream>
#include <vector>
int main() {
    int a;
    std::cin >> a;
    std::vector <char> s;
    for (int i = 0; i < a; i++) {
        int q;
        std::cin >> q;
        s.push_back(char(q));
    }
    int p = 2 * a + int(s[0]) + int(s[a - 1]);
    for (int j = 0; j < a - 1; j++) {
            p += abs(int(s[j]) - int(s[j + 1]));
    }
    std::cout << p;
    return 0;
}