#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> g;
vector<char> used;
vector<int> h;
int cnt = 0;
void dfs(int v) {
    used[v] = true;
    h[v] = cnt + 1;
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
    h.assign(n, 0);
    g.assign(n, {});
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    used.assign(n, false);
    cnt = 0;
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            dfs(i);
            cnt++;
        }
    cout << cnt << '\n';

    for (auto i : h) {
        cout << i << " ";
    }
    system("pause");
}