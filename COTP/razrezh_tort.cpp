#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int y, x;
    cin >> x >> y;
    int a = x, b = y;
    while (x != y) {
        if (x > y) x = x - y;
        else y = y - x;
    }
    cout << a * b / x;
}