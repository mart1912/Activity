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
    
    vector<vector<int>> Gr(N);

    for (int i =  0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        
        if (from >= N || to >= N) {
            continue;
        }
        
        Gr[from].push_back(to);
    }
    
    for (int i = 0; i < N; ++i) {
        sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    }
    
    cout << "\nOut-degrees:\n";
    for (int i = 0; i < N; ++i) {
        cout << i << ": " << Gr[i].size() << "\n";
    }
    
    return 0;
}