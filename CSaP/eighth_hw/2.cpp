#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printgraph(const vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        cout << i << ": ";
        for (int j : graph[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    int N, M;
    cout << "n: ";
    cin >> N;
    cout << "m: ";
    cin >> M;
    
    vector<vector<int>> Gr(N);
    
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
    
    cout << "\nOriginal graph:\n";
    printgraph(Gr);
    
    int A, B;
    cout << "\nEnter edge to remove (A B): ";
    cin >> A >> B;

    auto itA = find(Gr[A].begin(), Gr[A].end(), B);
    if (itA != Gr[A].end()) {
        Gr[A].erase(itA);
    }
    
    auto itB = find(Gr[B].begin(), Gr[B].end(), A);
    if (itB != Gr[B].end()) {
        Gr[B].erase(itB);
    }
    
    // Выводим обновлённый граф
    cout << "\nGraph after removing edge " << A << "-" << B << ":\n";
    printgraph(Gr);
    
    return 0;
}