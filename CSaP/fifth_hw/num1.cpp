#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct queue {
    int inf;
    queue *next;
};

void push(queue *&h, queue *&t, int x){ //вставка элемента в очередь
    queue *r = new queue; //создаем новый элемент
    r -> inf = x;
    r -> next = NULL; //всегда последний
    if (!h && !t){ //если очередь пуста
        h = t = r; //это и голова и хвост
    }
    else {
        t -> next = r; //r - следующий для хвоста
        t = r; //теперь r - хвост
    }
}

int pop(queue *&h, queue *&t){ //удаление элемента из очереди
    queue *r = h; //создаем указатель на голову
    int i = h -> inf; //сохраняем значение головы
    h = h -> next; //сдвигаем указатель на следующий элемент
    if (!h) //если удаляем последний элемент из очереди
        t = NULL;
    delete r; //удаляем первый элемент
    return i;
}

int main() {
    queue *head = NULL, *tail = NULL;
    int n, x;
    
    cout << "n = ";
    cin >> n;
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        push(head, tail, x);
    }
    
    int first = head->inf;
    int max_elem = first;
    
    queue *temp_head = NULL, *temp_tail = NULL;
    while (head) {
        x = pop(head, tail);
        if (x > max_elem) max_elem = x;
        push(temp_head, temp_tail, x);
    }
    
    while (temp_head) {
        x = pop(temp_head, temp_tail);
        push(head, tail, x);
        if (x == first) {
            push(head, tail, max_elem);
        }
    }
    
    while (head) {
        x = pop(head, tail);
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}