#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool prost(int n) {
    if (n < 2) return false;
    else
        for (int i = 2; i <= (int) sqrt(n); i++)
            if (n % i == 0) return false;
    return true;
}

struct stack{
    int inf;
    stack *next;
};

void push(stack *&h, int x){//вставка
    stack *r = new stack;
    r-> inf = x;
    r -> next = h;
    h = r;
}

int pop (stack *&h){ //удаление
    int i = h -> inf;
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
    stack *res = NULL;
    int cnt = 0;
    while (h) {
        int x = pop(h);
        if (prost(x)) push(res, 0);
        push(res, x);
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
    int x;
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