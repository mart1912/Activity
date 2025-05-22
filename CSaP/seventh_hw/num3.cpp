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

tree* Min(tree* tr) {
    if (!tr->left) return tr;
    else return Min(tr->left);
}

void Delete(tree*& tr, tree* v) {
    tree* p = v->parent;
    if (!p && !v->left && !v->right) {
        tr = NULL;
        return;
    }
    if (!v->left && !v->right) {
        if (p->left == v)
            p->left = NULL;
        else
            p->right = NULL;
        delete v;
    }
    else if (!v->left || !v->right) {
        if (!p) {
            if (v->left) {
                tr = v->left;
                tr->parent = NULL;
            }
            else {
                tr = v->right;
                tr->parent = NULL;
            }
        }
        else {
            if (v->left) {
                if (p->left == v)
                    p->left = v->left;
                else
                    p->right = v->left;
                v->left->parent = p;
            }
            else {
                if (p->left == v)
                    p->left = v->right;
                else
                    p->right = v->right;
                v->right->parent = p;
            }
        }
        delete v;
    }
    else {
        tree* succ = Min(v->right);
        v->inf = succ->inf;
        Delete(tr, succ);
    }
}

void inorder(tree* tr) {
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

int main() {
    int n, x, target;
    cout << "n = "; cin >> n;
    tree* tr = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(tr, x);
    }

    cout << "Tree before: ";
    inorder(tr);
    cout << endl;

    cout << "X: "; cin >> target;
    tree* nodeX = find(tr, target);

    tree* parent = nodeX->parent;
    tree* grandparent = NULL;
    if (parent) grandparent = parent->parent;

    if (grandparent) {
        Delete(tr, grandparent);
    }
    else {
        cout << "No grandparent to delete" << endl;
    }

    cout << "Tree after: ";
    inorder(tr);
    cout << endl;

    return 0;
}