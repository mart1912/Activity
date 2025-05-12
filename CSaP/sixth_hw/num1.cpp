#include <iostream>
using namespace std;
struct list {
    int inf;
    list *next;
    list *prev;
};

void push (list *&h, list *&t, int x){ //вставка элемента в конец списка
    list *r = new list; //создаем новый элемент
    r->inf = x;
    r->next = NULL; //всегда последний
    if (!h && !t){ //если список пуст
        r->prev = NULL; //первый элемент
        h = r; //это голова
    }
    else {
        t->next = r; //r - следующий для хвоста
        r->prev = t; //хвост - предыдущий для r
    }
    t = r; //r теперь хвост
}

void print (list *h, list *t){ //печать элементов списка
    list *p = h; //укзатель на голову
    while (p){ //пока не дошли до конца списка
        cout << p->inf << " ";
        p = p->next; //переход к следующему элементу
    }
}

void insert_after (list *&h, list *&t, list *r, int y){ //вставляем после r
    list *p = new list; //создаем новый элемент
    p->inf = y;
    if (r == t){ //если вставляем после хвоста
        p->next = NULL; //вставляемый эл-т - последний
        p->prev = r; //вставляем после r
        r->next = p;
        t = p; //теперь хвост - p
    }
    else { //вставляем в середину списка
        r->next->prev = p; //для следующего за r эл-та предыдущий - p
        p->next = r->next; //следующий за p - следующий за r
        p->prev = r; //p вставляем после r
        r->next = p;
    }
}

void insert_min_after_first(list *&h, list *&t, int k) {    
    int first = h->inf;
    int min_val = k;
    
    list *p = h;
    while (p) {
        if (p->inf == first) {
            insert_after(h, t, p, min_val);
            p = p->next; // переходим через только что вставленный элемент
        }
        p = p->next;
    }
}

int main() {
    list *head = NULL;
    list *tail = NULL;
    int n, x;
    cin >> n;
    int min = 10000000;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (min > x) min = x;
        push(head, tail, x);
    }
    insert_min_after_first(head, tail, min);
    print(head, tail);
    cout << endl;
    return 0;
}