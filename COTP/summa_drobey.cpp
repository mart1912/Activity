#include<iostream>
#include <vector>
using namespace std;
const int MOD = 998244353;
int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}
int mul(int a, int b) {
	return a * 1ll * b % MOD;
}
int binpow(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
int inv(int x) {
	return binpow(x, MOD - 2);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	for (int o = 0; o < n; o++) {
		cin >> p[o];
	}
	for (int o = 0; o < n; o++) {
		cin >> q[o];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = mul(p[i], inv(q[i]));
		ans = add(ans, l);
	}
	cout << ans;
	return 0;
}