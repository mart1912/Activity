#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n % 5 < 3) cout << n - n % 5;
    else cout << n - (n % 5) + 5;
    return 0;
}