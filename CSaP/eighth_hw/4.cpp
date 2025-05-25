#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Gr;
vector<bool> used;
vector<int> path;

void dfs(int x) {
    used[x] = 1;
    path.push_back(x);
    
    for (int i = 0; i < Gr[x].size(); ++i) {
        int neighbor = Gr[x][i];
        if (!used[neighbor])
            dfs(neighbor);
    }
}

int main() {
    int N, M;
    cout << "n: ";
    cin >> N;
    cout << "m: ";
    cin >> M;
    
    Gr.resize(N);
    used.assign(N, 0);

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        
        if (x >= N || y >= N) {
            continue;
        }
        
        Gr[x].push_back(y);
        Gr[y].push_back(x);
    }
    
    for (int i = 0; i < N; ++i) {
        sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    }

    dfs(0);
    
    bool connect = true;
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            connect = false;
            break;
        }
    }
    
    if (connect) {
        cout << "The graph is CONNECTED\n";
    } else {
        cout << "The graph is DISCONNECTED\n";
    }
    
    cout << "DFS: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << '\n';
    
    return 0;
}