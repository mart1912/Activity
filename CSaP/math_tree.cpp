#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct tree{ //����
    char inf;
    tree *right;
    tree *left;
    tree *parent;
};

tree *node(char x){ //�������� ����
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

tree *create_tree( string str ){ //�������� ������
    tree *tr = NULL;
    for (unsigned int i = 0; i < str.length(); i++){ //������ �� ������
        tree *n = node(str[i]) ;
        if (str[i] == '-' || str[i] == '+'){//���������� ������
            tr->parent = n;
            n->left = tr; //��������� ������ ���������� �����
            tr = n;
        }
        else if (str[i] == '/' || str[i] == '*'){
            if (isdigit(tr->inf)){ //���� ������ ���� �������� � ��������� - ������
                tr->parent = n;
                n->left = tr;
                tr = n;
            }
            else{ //��������� ������ �� �����
                n->parent = tr;
                n->left = tr->right;//��������� ������� ���������� �����
                tr->right->parent = n;
                tr->right = n;
            }
        }
        else { //�����
            if (!tr) tr = n; //���� ������ � ��������� - ���������� ������
            else{ //���
                if (!tr->right){//� ����� ��� ������� ����, ���������� ��
                    n->parent = tr;
                    n->left = tr->right;
                    tr->right = n;
                }
                else {//���� ������� ��� ������� ����
                    tree *x = tr->right;
                    while (x->right) x = x->right;
                    n->parent = x->parent;
                    x->right = n;
                }
            }
        }
    }
    return tr;
}

void postorder(tree *tr, stack<int> &a){//�������� �����
    if (tr){
        postorder(tr->left, a);
        postorder(tr->right, a);
        if (isdigit(tr->inf)){ //���� ���� -�����, ���������� � ����
            int n = tr->inf - '0';
            a.push(n);
        }
        else{//���� ��������
            int b = a.top();//��������� 2 ��������� �������� �����
            a.pop();
            int c = a.top();
            a.pop();
            if(tr->inf == '+') a.push(b + c); //� ���������� � ����
            if(tr->inf == '-') a.push(c - b); //��������� � ���.
            if(tr->inf == '*') a.push(b * c); //�� ����� ��������
            if(tr->inf == '/') a.push(c / b);
        }
        cout << tr->inf;
    }
}

void preorder(tree *tr, stack<int> &a){//������ �����
    if (tr){
        cout << tr->inf;
        preorder(tr->left, a);
        preorder(tr->right, a);
        if (isdigit(tr->inf)){ //���� ���� -�����, ���������� � ����
            int n = tr->inf - '0';
            a.push(n);
        }
        else{//���� ��������
            int b = a.top();//��������� 2 ��������� �������� �����
            a.pop();
            int c = a.top();
            a.pop();
            if(tr->inf == '+') a.push(b + c); //� ���������� � ����
            if(tr->inf == '-') a.push(c - b); //��������� � ���.
            if(tr->inf == '*') a.push(b * c); //�� ����� ��������
            if(tr->inf == '/') a.push(c / b);
        }
    }
}

int main(){
    string str;
    cout << "Mathematical expression: ";
    getline(cin, str);
    string znak = "+-/*0123456789()";
    bool flag = true;
    for (unsigned int i = 0; i < str.length(); i++)//��������� �������� �� ������������ �����
        if (znak.find_first_of(str[i]) == string::npos) {
            flag = false;
            break;
        }
    if (!flag) cout << "error";
    else {
        tree *tr = create_tree(str);//������� ������
        stack<int> a;
        cout << "Postfix form: ";
        postorder(tr, a);//������� �����
        cout << '\n';
        a.pop();
        cout << "Prefix form: ";
        preorder(tr, a);//������� �����
        cout << '\n';
        a.pop();
    }
    return 0;
}