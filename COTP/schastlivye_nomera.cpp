#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		sum += 1ll << i;
	cout << sum;
	return 0;
}
