#include <iostream>
using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x) { //вставка элемента в конец списка
    list *r = new list; //создаем новый элемент
    r->inf = x;
    r->next = NULL; //всегда последний
    if (!h && !t) { //если список пуст
        r->prev = NULL; //первый элемент
        h = r; //это голова
    }
    else {
        t->next = r; //r - следующий для хвоста
        r->prev = t; //хвост - предыдущий для r
    }
    t = r; //r теперь хвост
}

void print(list *h, list *t) { //печать элементов списка
    list *p = h; //укзатель на голову
    while (p) { //пока не дошли до конца списка
        cout << p->inf << " ";
        p = p->next; //переход к следующему элементу
    }
    cout << endl;
}

bool prost(int n) {
    if (n < 2) return false;
    else
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
    return true;
}

void to_first_prost(list *&h, list *&t) {
    list *first_prime = h;
    while (first_prime) {
        if (prost(first_prime->inf)) {
            break;
        }
        first_prime = first_prime->next;
    }

    list *new_head = first_prime;
    list *new_tail = first_prime->prev;
    
    new_tail->next = NULL;
    new_head->prev = NULL;
    
    t->next = h;
    h->prev = t;
    
    h = new_head;
    t = new_tail;
}

int main() {
    list *head = NULL, *tail = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, tail, x);
    }
    to_first_prost(head, tail);
    print(head, tail);
    return 0;
}