#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> g;
vector<char> used;
vector<int> p;

void dfs(int v) {
	used[v] = true;
	for (int u : g[v]) {
		if (!used[u]) {

			dfs(u);
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	g.assign(n, {});
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		--v; --u;

		g[v].push_back(u);
		g[u].push_back(v);
	}

	used.assign(n, false);
	dfs(0);
	
	if (m == n - 1 && all_of(used.begin(), used.end(), [](char i) {return i; })) cout << "YES\n";
	else cout << "NO\n";
	system("pause");
}
