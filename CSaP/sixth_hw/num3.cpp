#include <iostream>
using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};

void push(list *&h, list *&t, int x) {
    list *r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list *h) {
    list *p = h;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

void del_node(list *&h, list *&t, list *r) {
    if (r == h && r == t) {
        h = t = NULL;
    }
    else if (r == h) {
        h = h->next;
        h->prev = NULL;
    }
    else if (r == t) {
        t = t->prev;
        t->next = NULL;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

double calculate_avg(list *r) {
    if (!r || !r->next) 
        return r->inf;
    int sum = 0, count = 0;
    list *p = r->next;
    while (p) {
        sum += p->inf;
        count++;
        p = p->next;
    }
    return (double)sum / count;
}

void filter_list(list *&h, list *&t) {
    list *current = h;
    while (current) {
        list *next_node = current->next;
        double avg = calculate_avg(current);
        if (current->inf > avg) {
            del_node(h, t, current);
        }
        current = next_node;
    }
}

int main() {
    list *head = NULL, *tail = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, tail, x);
    }
    filter_list(head, tail);
    print(head);
    return 0;
}