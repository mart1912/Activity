//Eulerian cycle
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void EulerianCycle(vector<vector<int>>& graph, int N) {
    vector<int> degrees(N, 0);
    for (int i = 0; i < N; ++i) {
        degrees[i] = graph[i].size();
    }

    int v1 = -1, v2 = -1;
    for (int i = 0; i < N; ++i) {
        if (degrees[i] % 2 != 0) {
            if (v1 == -1) {
                v1 = i;
            } else if (v2 == -1) {
                v2 = i;
            } else {
                cout << "No Eulerian cycle exists" << endl;
                return;
            }
        }
    }

    if (v1 != -1 && v2 != -1) {
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        degrees[v1]++;
        degrees[v2]++;
    } else if (v1 != -1) {
        cout << "No Eulerian cycle exists" << endl;
        return;
    }

    stack<int> st;
    vector<int> res;

    int start_vertex = (v1 != -1) ? v1 : 0;
    st.push(start_vertex);

    while (!st.empty()) {
        int current = st.top();
        
        if (degrees[current] > 0) {
            int next = graph[current].back();
            graph[current].pop_back();

            auto it = find(graph[next].begin(), graph[next].end(), current);
            if (it != graph[next].end()) {
                graph[next].erase(it);
            }
            
            degrees[current]--;
            degrees[next]--;
            
            st.push(next);
        } else {
            res.push_back(current);
            st.pop();
        }
    }

    if (v1 != -1) {
        for (size_t i = 0; i + 1 < res.size(); ++i) {
            if ((res[i] == v1 && res[i+1] == v2) || (res[i] == v2 && res[i+1] == v1)) {
                vector<int> new_res;
                new_res.insert(new_res.end(), res.begin() + i + 1, res.end() - 1);
                new_res.insert(new_res.end(), res.begin(), res.begin() + i + 1);
                res = new_res;
                break;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (!graph[i].empty()) {
            cout << "No Eulerian cycle exists" << endl;
            return;
        }
    }

    cout << "Eulerian cycle: ";
    for (int vertex : res) {
        cout << vertex << " ";
    }
    cout << endl;
}

int main() {
    int N, M;
    cout << "n = ";
    cin >> N;
    cout << "m = ";
    cin >> M;

    vector<vector<int>> graph(N);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    EulerianCycle(graph, N);

    return 0;
}