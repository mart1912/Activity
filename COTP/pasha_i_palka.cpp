#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n % 4 == 0) cout << n / 4 - 1;
	else cout << n / 4;
	return 0;
}