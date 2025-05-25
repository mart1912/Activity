#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;      
vector<int> topolog;
bool hasCycle = false;

void dfs(int x) {
    visited[x] = true;
    for (int neighbor : graph[x]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
        else if (find(topolog.begin(), topolog.end(), neighbor) == topolog.end()) {
            hasCycle = true;
        }
    }
    topolog.push_back(x);
}

int main() {
    int N, M;
    cout << "n = ";
    cin >> N;
    cout << "m = ";
    cin >> M;

    graph.resize(N);
    visited.assign(N, false);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    if (hasCycle) {
        cout << "Topological sorting is not possible" << endl;
    }
    else {
        reverse(topolog.begin(), topolog.end());
        cout << "Topological order of vertices:" << endl;
        for (int v : topolog) {
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}