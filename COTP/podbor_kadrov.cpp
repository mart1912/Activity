#include <iostream>
#include <vector>
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
	for (int i = 0; i <= n; i++) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	cout << c[n][5] + c[n][6] + c[n][7];
	return 0;
}
