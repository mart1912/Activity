#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long y = 1ll * n * 1ll * (n - 1) * 1ll * (n - 2) * 1ll * (n - 3) * 1ll * (n - 4);
	long long sum = 1ll * (y / 120 + y * 1ll * (n - 5) / 720 + y * 1ll * (n - 5) * 1ll * (n - 6) / 5040);
	cout << sum;
	return 0;
}