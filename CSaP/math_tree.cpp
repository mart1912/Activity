#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct tree{ //узел
    char inf;
    tree *right;
    tree *left;
    tree *parent;
};

tree *node(char x){ //создание узла
    tree *n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

tree *create_tree( string str ){ //создание дерева
    tree *tr = NULL;
    for (unsigned int i = 0; i < str.length(); i++){ //проход по строке
        tree *n = node(str[i]) ;
        if (str[i] == '-' || str[i] == '+'){//становится корнем
            tr->parent = n;
            n->left = tr; //имеющееся дерево становится левым
            tr = n;
        }
        else if (str[i] == '/' || str[i] == '*'){
            if (isdigit(tr->inf)){ //если первый знак операции в выражении - корень
                tr->parent = n;
                n->left = tr;
                tr = n;
            }
            else{ //добавляем справа от корня
                n->parent = tr;
                n->left = tr->right;//имеющийся элемент становится левым
                tr->right->parent = n;
                tr->right = n;
            }
        }
        else { //цифра
            if (!tr) tr = n; //если первая в выражении - становится корнем
            else{ //нет
                if (!tr->right){//у корня нет правого сына, становится им
                    n->parent = tr;
                    n->left = tr->right;
                    tr->right = n;
                }
                else {//ищем операнд без правого сына
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

void postorder(tree *tr, stack<int> &a){//обратный обход
    if (tr){
        postorder(tr->left, a);
        postorder(tr->right, a);
        if (isdigit(tr->inf)){ //если узел -число, записываем в стек
            int n = tr->inf - '0';
            a.push(n);
        }
        else{//знак операции
            int b = a.top();//извлекаем 2 последних элемента стека
            a.pop();
            int c = a.top();
            a.pop();
            if(tr->inf == '+') a.push(b + c); //и записываем в стек
            if(tr->inf == '-') a.push(c - b); //результат в зав.
            if(tr->inf == '*') a.push(b * c); //от знака операции
            if(tr->inf == '/') a.push(c / b);
        }
        cout << tr->inf;
    }
}

void preorder(tree *tr, stack<int> &a){//прямой обход
    if (tr){
        cout << tr->inf;
        preorder(tr->left, a);
        preorder(tr->right, a);
        if (isdigit(tr->inf)){ //если узел -число, записываем в стек
            int n = tr->inf - '0';
            a.push(n);
        }
        else{//знак операции
            int b = a.top();//извлекаем 2 последних элемента стека
            a.pop();
            int c = a.top();
            a.pop();
            if(tr->inf == '+') a.push(b + c); //и записываем в стек
            if(tr->inf == '-') a.push(c - b); //результат в зав.
            if(tr->inf == '*') a.push(b * c); //от знака операции
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
    for (unsigned int i = 0; i < str.length(); i++)//частичная проверка на корректность ввода
        if (znak.find_first_of(str[i]) == string::npos) {
            flag = false;
            break;
        }
    if (!flag) cout << "error";
    else {
        tree *tr = create_tree(str);//создали дерево
        stack<int> a;
        cout << "Postfix form: ";
        postorder(tr, a);//вызвали обход
        cout << '\n';
        a.pop();
        cout << "Prefix form: ";
        preorder(tr, a);//вызвали обход
        cout << '\n';
        a.pop();
    }
    return 0;
}