#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct queue {
    int inf;
    queue* next;
};

void qpush(queue*& h, queue*& t, int x) {
    queue* r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        h = t = r;
    }
    else {
        t->next = r;
        t = r;
    }
}

int qpop(queue*& h, queue*& t) {
    queue* r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

using Cell = pair<int, int>;

Cell chessToCoord(const string& pos) {
    return {toupper(pos[0]) - 'A', pos[1] - '1'};
}

string coordToChess(const Cell& c) {
    return string(1, 'A' + c.first) + to_string(c.second + 1);
}

vector<Cell> findKnightPath(const Cell& start, const Cell& end) {
    const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};


    const int N = 64;
    vector<vector<int>> Gr(N);
    
    
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            int from = x * 8 + y;
            for (int k = 0; k < 8; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                    int to = nx * 8 + ny;
                    Gr[from].push_back(to);
                }
            }
        }
    }

    vector<int> visited(N, 0);
    vector<int> parent(N, -1);
    queue* qh = NULL, *qt = NULL;

    int start_idx = start.first * 8 + start.second;
    int end_idx = end.first * 8 + end.second;

    qpush(qh, qt, start_idx);
    visited[start_idx] = 1;

    while (qh) {
        int current = qpop(qh, qt);
        if (current == end_idx) break;

        for (int neighbor : Gr[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                parent[neighbor] = current;
                qpush(qh, qt, neighbor);
            }
        }
    }

    vector<Cell> path;
    if (visited[end_idx]) {
        for (int at = end_idx; at != -1; at = parent[at])
            path.push_back({at / 8, at % 8});
        reverse(path.begin(), path.end());
    }

    return path;
}

int main() {
    string from, to;
    cin >> from;
    cin >> to;

    Cell start = chessToCoord(from);
    Cell end = chessToCoord(to);

    vector<Cell> path = findKnightPath(start, end);

    for (size_t i = 0; i < path.size(); ++i)
        cout << coordToChess(path[i]) << " ";
    cout << endl;

    return 0;
}