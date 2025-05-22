//15. Дано дерево. Вывести все листья
#include <iostream>
using namespace std;
struct Tree {
    int inf;
    Tree *left;
    Tree *right;
    Tree *parent;
    char color;
};

void inorder(Tree *tr) {
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

void left_rotate(Tree *&tr, Tree *x){
    Tree *y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent->left == x) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
    if (!y->parent) {
        tr = y;
        y->color = 'b';
    }
}

void right_rotate(Tree *&tr, Tree *x){
    Tree *y = x->left;
    x->left = y->right;
    if (y->right) y->right->parent = x;
    y->parent = x->parent;
    if (x->parent->left == x) x->parent->left = y;
    else x->parent->right = y;
    y->right = x;
    x->parent = y;
    if (!y->parent) {
        tr = y;
        y->color = 'b';
    }
}

Tree *root(int X) {
    Tree *n = new Tree;
    n->inf = X;
    n->left = n->right = NULL;
    n->parent = NULL;
    n->color = 'b';
    return n;
}

Tree *node(Tree *prev, int X) {
    Tree *n = new Tree;
    n->inf = X;
    n->left = n->right = NULL;
    n->parent = prev;
    n->color = 'r';
    return n;
}

Tree *grandfather(Tree *X) {
    if (X && X->parent) return X->parent->parent;
    else return NULL;
}

Tree *uncle(Tree *X) {
    Tree *g = grandfather(X);
    if (!g) return NULL;
    if (X->parent == g->left) return g->right;
    else return g->left;
}

Tree *brother(Tree *X) {
    if (X && X->parent) {
        if (X == X->parent->left) return X->parent->right;
        else return X->parent->left;
    }
    else return NULL;
}

void insert_case1(Tree *&tr, Tree *X);
void insert_case2(Tree *&tr, Tree *X);
void insert_case3(Tree *&tr, Tree *X);
void insert_case4(Tree *&tr, Tree *X);
void insert_case5(Tree *&tr, Tree *X);

void insert_case1(Tree *&tr, Tree *X) {
    if (!X->parent) X->color = 'b';
    else insert_case2(tr, X);
}

void insert_case2(Tree *&tr, Tree *X) {
    if (X->parent->color == 'r') insert_case3(tr, X);
}

void insert_case3(Tree *&tr, Tree *X) {
    Tree *g = grandfather(X);
    Tree *u = uncle(X);
    if (u && u->color == 'r' && X->parent->color == 'r') {
        X->parent->color = 'b';
        u->color = 'b';
        g->color = 'r';
        insert_case1(tr, g);
    }
    else insert_case4(tr, X);
}

void insert_case4(Tree *&tr, Tree *X) {
    Tree *g = grandfather(X);
    Tree *p = X->parent;
    if (p->right == X && g->left == p) {
        left_rotate(tr, X);
        X = X->left;
    }
    else if (p->left == X && g->right == p) {
        right_rotate(tr, X);
        X = X->right;
    }
    insert_case5(tr, X);
}

void insert_case5(Tree *&tr, Tree *X) {
    Tree *g = grandfather(X);
    Tree *p = X->parent;
    p->color = 'b';
    g->color = 'r';
    if (X == p->right && p == g->right) left_rotate(tr, g);
    else right_rotate(tr, g);
}

void insert(Tree *&tr, Tree *prev, int X) {
    if (X < prev->inf && prev->left == NULL) {
        prev->left = node(prev, X);
        insert_case1(tr, prev->left);
    }
    else if (X > prev->inf && prev->right == NULL) {
        prev->right = node(prev, X);
        insert_case1(tr, prev->right);
    }
    else if (X < prev->inf && prev->left != NULL) insert(tr, prev->left, X);
    else if (X > prev->inf && prev->right != NULL) insert(tr, prev->right, X);
}

void delete_case1(Tree *&tr, Tree *X);
void delete_case2(Tree *&tr, Tree *X);
void delete_case3(Tree *&tr, Tree *X);
void delete_case4(Tree *&tr, Tree *X);
void delete_case5(Tree *&tr, Tree *X);
void delete_case6(Tree *&tr, Tree *X);

void delete_case1(Tree *&tr, Tree *X) {
    if (!X->parent) {
        if (X -> left) tr = X->left;
        else tr = X->right;
    }
    else delete_case2(tr, X);
}

void delete_case2(Tree *&tr, Tree *X) {
    Tree *B = brother(X);
    Tree *P = X->parent;
    if (B->color == 'r') {
        P->color = 'r';
        B->color = 'b';
        if (P->left == X) left_rotate(tr, P);
        else right_rotate(tr, P);
    }
    delete_case3(tr, X);
}

void delete_case3(Tree *&tr, Tree *X) {
    Tree *B = brother(X);
    if (X->parent->color == 'b' && B->color == 'b' && (!B->left || B->left->color == 'b')
     && (!B->right || B->right->color == 'b')) {
        B->color = 'r';
        delete_case1(tr, X);
    }
    else delete_case4(tr, X);
}

void delete_case4(Tree *&tr, Tree *X) {
    Tree *P = X->parent;
    Tree *B = brother(X);
    if (X->parent->color == 'r' && B->color == 'b' && (!B->left || B->left->color == 'b')
     && (!B->right || B->right->color == 'b')) {
        B->color = 'r';
        P->color = 'b';
    }
    else delete_case5(tr, X);
}

void delete_case5(Tree *&tr, Tree *X) {
    Tree *B = brother(X);
    Tree *P = X->parent;
    if (B->color == 'r') {
        if (P->left == X && (B->left && B->left->color == 'r') && (!B->right || B->right->color == 'b')) {
            B->left->color = 'b';
            B->color = 'r';
            right_rotate(tr, B);
        }
        else if (P->right == X && (B->right && B->right->color == 'r') && (!B->left || B->left->color == 'b')) {
            B->left->color = 'b';
            B->color = 'r';
            left_rotate(tr, B);
        }
    }
    delete_case6(tr, X);
}

void delete_case6(Tree *&tr, Tree *X) {
    Tree *P = X->parent;
    Tree *B = brother(X);
    B->color = P->color;
    P->color = 'b';
    if (X == P->left) {
        B->right->color = 'b';
        left_rotate(tr, P);
    }
    else {
        B->left->color = 'b';
        right_rotate(tr, P);
    }
}

void replace(Tree *&tr, Tree *X) {
    if (X->left) {
        Tree *ch = X->left;
        ch->parent = X->parent;
        if (X->parent) {
            if (X == X->parent->left) X->parent->left = ch;
            else X->parent->right = ch;
        }
    }
    else {
        Tree *ch = X->right;
        ch->parent = X->parent;
        if (X->parent) {
            if (X = X->parent->left) X->parent->left = ch;
            else X->parent->right = ch;
        }
    }
}

void erase(Tree *&tr, Tree *X) {
    if (X->left && X->right) {
        Tree *buf = NULL;
        if (X->inf <= tr->inf) {
            buf = X->left;
            while (buf->right) buf = buf->right;
        }
        else {
            buf = X->right;
            while (buf->left) buf = buf->left;
        }
        X->inf = buf->inf;
        X = buf;
    }
    else if (X->left || X->right) {
        Tree *ch = NULL;
        if (X->left) ch = X->left;
        else ch = X->right;
        replace(tr, X);
        if (X->color == 'b') {
            if (ch->color == 'r') ch->color = 'b';
            else delete_case1(tr, X);
        }
    }
    else {
        if (X->color == 'b') delete_case1(tr, X);
        else {
            if (X == X->parent->left) X->parent->left = NULL;
            else X->parent->right = NULL;
        }
    }
}

void print_listya(Tree *tr) {
    if (tr) {
        if (!tr->left && !tr->right) cout << tr->inf << " ";
        print_listya(tr->left);
        print_listya(tr->right);
    }
}

int main() {
    Tree *tr = NULL;
    int n, k;
    cout << "n = ";
    cin >> n;
    cout << "Tree elements: ";
    cin >> k;
    tr = root(k);
    for (int i = 1; i < n; i++) {
        cin >> k;
        insert(tr, tr, k);
    }
    cout << "Symmetrical bypass: ";
    inorder(tr);
    cout << '\n';
    cout << "Tree leaves: ";
    print_listya(tr);
    cout << '\n';
}