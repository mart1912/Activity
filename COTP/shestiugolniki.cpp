#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long sum = n * (n + 1) / 2;
	cout << sum * 6 + 1;
	return 0;
}