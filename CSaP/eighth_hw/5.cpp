#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Gr;
vector<vector<int>> GrT;
vector<bool> used;
vector<int> order;
vector<int> path;

void dfs1(int x) {
    used[x] = 1;
    for (int i = 0; i < Gr[x].size(); ++i) {
        int neighbor = Gr[x][i];
        if (!used[neighbor]) {
            dfs1(neighbor);
        }
    }
    order.push_back(x);
}

void dfs2(int x) {
    used[x] = 1;
    path.push_back(x);
    for (int i = 0; i < GrT[x].size(); ++i) {
        int neighbor = GrT[x][i];
        if (!used[neighbor]) {
            dfs2(neighbor);
        }
    }
}

int main() {
    int N, M;
    cout << "n: ";
    cin >> N;
    cout << "m: ";
    cin >> M;

    Gr.resize(N);
    GrT.resize(N);

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;

        if (x >= N || y >= N) {
            continue;
        }

        Gr[x].push_back(y);
        GrT[y].push_back(x);
    }

    used.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }

    used.assign(N, 0);
    reverse(order.begin(), order.end());

    cout << "\nStrongly Connected Components:\n";
    for (int i = 0; i < N; ++i) {
        int v = order[i];
        if (!used[v]) {
            path.clear();
            dfs2(v);
            for (int vertex : path) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }

    return 0;
}