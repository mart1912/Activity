#include <iostream>
using namespace std;

struct tree {
    int inf;
    tree* right;
    tree* left;
    tree* parent;
};

tree* node(int x) {
    tree* n = new tree;
    n->inf = x;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x) {
    tree* n = node(x);
    if (!tr) tr = n;
    else {
        tree* y = tr;
        while (y) {
            if (n->inf > y->inf) {
                if (y->right) y = y->right;
                else {
                    n->parent = y;
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf) {
                if (y->left) y = y->left;
                else {
                    n->parent = y;
                    y->left = n;
                    break;
                }
            }
        }
    }
}

tree* find(tree* tr, int x) {
    if (!tr || x == tr->inf)
        return tr;
    if (x < tr->inf)
        return find(tr->left, x);
    else
        return find(tr->right, x);
}

tree* findLCA(tree* root, tree* A, tree* B) {
    if (!root) return NULL;
    if (root->inf > A->inf && root->inf > B->inf)
        return findLCA(root->left, A, B);
    if (root->inf < A->inf && root->inf < B->inf)
        return findLCA(root->right, A, B);
    return root;
}

int distanceFromNode(tree* node, tree* target) {
    int distance = 0;
    while (node != target) {
        if (target->inf < node->inf)
            node = node->left;
        else
            node = node->right;
        distance++;
        if (!node) return -1;
    }
    return distance;
}

int main() {
    int n, x;
    cout << "n = "; cin >> n;
    tree* tr = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(tr, x);
    }

    int A, B;
    cout << "Enter node A: "; cin >> A;
    cout << "Enter node B: "; cin >> B;

    tree* A_node = find(tr, A);
    tree* B_node = find(tr, B);
    tree* lca = findLCA(tr, A_node, B_node);
    if (!lca) {
        cout << "Path does not exist" << endl;
        return 0;
    }

    int distA = distanceFromNode(lca, A_node);
    int distB = distanceFromNode(lca, B_node);

    cout << "Path length: " << distA + distB << endl;

    return 0;
}