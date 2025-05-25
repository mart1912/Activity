#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cout << "n: ";
    cin >> N;
    cout << "m: ";
    cin >> M;
    
    vector<vector<int>> Gr;
    Gr.resize(N);
    
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
    
    int given_vertex;
    cout << "Enter vertex: ";
    cin >> given_vertex;
    
    vector<bool> adjacent(N, false);
    for (int v : Gr[given_vertex]) {
        adjacent[v] = true;
    }
    adjacent[given_vertex] = true;
    
    cout << "Vertices not adjacent to " << given_vertex << ":" << endl;
    bool found = false;
    for (int i = 0; i < N; ++i) {
        if (!adjacent[i]) {
            cout << i << " ";
            found = true;
        }
    }
    
    cout << endl;
    
    return 0;
}