#include <iostream>
#include <vector>
using namespace std;

struct stack {
    int inf;
    stack* next;
};

void spush(stack*& h, int x) {
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

int spop(stack*& h) {
    int i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

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

vector<vector<int>> readGraph(int N) {
    vector<vector<int>> Gr(N);
    cout << "Enter adjacency list (one line per vertex, numbers separated by spaces):\n";
    cin.ignore();
    
    for (int i = 0; i < N; ++i) {
        cout << i << ": ";
        vector<int> neighbors;
        char c;
        int num = 0;
        bool reading = false;
        
        while (cin.get(c) && c != '\n') {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                reading = true;
            } else if (reading) {
                neighbors.push_back(num);
                num = 0;
                reading = false;
            }
        }
        if (reading) {
            neighbors.push_back(num);
        }
        
        Gr[i] = neighbors;
    }
    return Gr;
}

void dfs(const vector<vector<int>>& Gr, int N, int x) {
    stack* h = NULL;
    vector<int> A(N, 0);
    int y;

    A[x] = 1;
    spush(h, x);
    cout << x << " ";
    bool fl;
    while (h) {
        x = h -> inf;
        fl = false;
        for (int neighbor : Gr[x]) {
            if (A[neighbor] == 0) {
                y = neighbor;
                fl = true;
                break;
            }
        }

        if (fl) {
            A[y] = 1;
            spush(h, y);
            cout << y << " ";
        } else {
            spop(h);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (A[i] == 0) {
            dfs(Gr, N, i);
        }
    }
}

void bfs(const vector<vector<int>>& Gr, int N, int x) {
    queue* h = NULL;
    queue* t = NULL;
    vector<int> A(N, 0);
    int y;
    
    A[x] = 1;
    qpush(h, t, x);
    cout << x << " ";
    
    while (h) {
        x = qpop(h, t);
        
        for (int neighbor : Gr[x]) {
            if (A[neighbor] == 0) {
                y = neighbor;
                A[y] = 1;
                qpush(h, t, y);
                cout << y << " ";
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        if (A[i] == 0) {
            bfs(Gr, N, i);
        }
    }
}

int main() {
    int n, x;
    cout << "Enter number of vertices: ";
    cin >> n;
    
    vector<vector<int>> Gr = readGraph(n);
    
    cout << "Enter starting vertex: ";
    cin >> x;

    cout << "DFS traversal: ";
    dfs(Gr, n, x);
    cout << endl;

    cout << "BFS traversal: ";
    bfs(Gr, n, x);
    cout << endl;

    return 0;
}