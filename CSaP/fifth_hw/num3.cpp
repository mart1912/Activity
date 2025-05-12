#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stack{
    char inf;
    stack *next;
};

void push(stack *&h, char x){//вставка
    stack *r = new stack;
    r-> inf = x;
    r -> next = h;
    h = r;
}

char pop (stack *&h){ //удаление
    char i = h -> inf;
    stack *r = h;
    h = h -> next;
    delete r;
    return i;
}

void reverse(stack *&h){ //"обращение"стека
    stack *head1 = NULL; //инициализация буферного стека
    while (h) //пока стек не пуст
    push(head1, pop(h)); //переписываем из одного стека в другой
    h = head1; //переобозначаем указатели
}

stack *result(stack *&h) {
    vector <char> sog = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    stack *res = NULL;
    int cnt = 0;
    while (h) {
        char x = pop(h);
        push(res, x);
        if (find(sog.begin(), sog.end(), x) != sog.end() && cnt == 0) {push(res, '!'); cnt++;}
    }
    reverse(res);
    return res;
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    cout << '\n';
    stack *head = NULL; //инициализация
    char x;
    for (int i = 0; i < n; i++){ //создаем стек
        cin >> x;
        push(head, x);
    }
    reverse(head); //переворачиваем стек
    stack *res = result(head); //результат
    while(res)
        cout << pop(res) << " "; //выводим на экран

    cout << endl;
    return 0;
}