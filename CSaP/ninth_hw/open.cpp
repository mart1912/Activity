#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

struct worker {
    string post;
    string surname;
    date date_of_birthday;
    int experience;
    int pay;
};

struct list {
    worker inf;
    list *prev;
    list *next;
};

struct List {
    list *h;
    list *t;
};

void push(list *&h, list *&t, worker x) {
    list *r = new list;
    r->inf = x;
    r->next = nullptr;
    if (!h && !t) {
        r->prev = nullptr;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print_worker(worker human) {
    string i = human.date_of_birthday.day / 10 == 0 ? "0" : "";
    string i1 = human.date_of_birthday.month / 10 == 0 ? "0" : "";
    cout << human.surname << ", " << human.experience << ", " << i << human.date_of_birthday.day << "." << i1 << human.date_of_birthday.month << "."
        << human.date_of_birthday.year << ", " << human.post << ", " << human.pay << endl;
}

void print(list *&h, list *&t) {
    list *p = h;
    while(p) {
        print_worker(p->inf);
        p = p->next;
    }
    cout << '\n';
}

vector<list*> find(list *&h, list *&t, int x) {
    vector<list*> ans;
    list *p = h;
    while(p) {
        if (p->inf.date_of_birthday.day == x) ans.push_back(p);
        p = p->next;
    }
    return ans;
}

void del_node(list *&h, list *&t, list *&r) {
    if (r == h && r == t) {
        h = t = nullptr;
    }
    else if (r == h) {
        h = h->next;
        h->prev = nullptr;
    }
    else if (r == t) {
        t = t->prev;
        t->next = nullptr;
    }
    else {
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

int h(int x, int M) {
    double A = (sqrt(5) - 1) / 2;
    return int(M * (x * A - int(x * A)));;
}

worker str_to_worker(string str) {
    worker human;
    size_t k = 0; size_t k1 = str.find_first_of(',');
    human.surname = str.substr(k, k1);
    k = k1 + 2; k1 = str.find_first_of(',', k);
    human.experience = stoi(str.substr(k, k1 - k));
    k = k1 + 2; k1 = str.find_first_of(',', k);
    size_t i = k; size_t i1 = str.find_first_of('.', k);
    human.date_of_birthday.day = stoi(str.substr(i, i1 - i));
    i = i1 + 1; i1 = str.find_first_of('.', i);
    human.date_of_birthday.month = stoi(str.substr(i, i1 - i));
    i = i1 + 1; i1 = str.find_first_of('.', i);
    human.date_of_birthday.year = stoi(str.substr(i, i1 - i));
    k = k1 + 2; k1 = str.find_first_of(',', k);
    human.post = str.substr(k, k1 - k);
    k = k1 + 2; k1 = str.find_first_of(',', k);
    human.pay = stoi(str.substr(k, k1 - k));
    return human;
}

vector<List> createHashTable(vector<worker> A, int M) {
    vector<List> hashTable(M);
    for (int i = 0; i < A.size(); i++) {
        int k = h(A[i].date_of_birthday.day, M);
        push(hashTable[k].h, hashTable[k].t, A[i]);
    }
    return hashTable;
}

void printHashTable(vector<List> hashTable) {
    for (int i = 0; i < hashTable.size(); i++) {
        cout << i << " : \n";
        print(hashTable[i].h, hashTable[i].t);
    }
}

void findHash(vector<List> hashTable, int x) {
    int k = h(x, hashTable.size());
    vector<list*> temp = find(hashTable[k].h, hashTable[k].t, x);
    if (temp.size() == 0) cout << "Not found\n";
    else
        for (int i = 0; i < temp.size(); i++) {
            print_worker(temp[i]->inf);
        }
}

void delHash(vector<List> &hashTable, int x) {
    int k = h(x, hashTable.size());
    vector<list*> temp = find(hashTable[k].h, hashTable[k].t, x);
    for (int i = 0; i < temp.size(); i++) {
        del_node(hashTable[k].h, hashTable[k].t, temp[i]);
    }
}

void enterHash(vector<List> &hashTable) {
    string x;
    cout << "Enter new element: ";
    getline(cin, x);
    worker temp = str_to_worker(x);
    int k = h(temp.date_of_birthday.day, hashTable.size());
    push(hashTable[k].h, hashTable[k].t, temp);
}

int main() {
    ifstream in("input.txt");
    vector<worker> A(20);
    int M = 16;
    string str;
    for (int i = 0; i < 20; i++) {
        getline(in, str);
        A[i] = str_to_worker(str);
    }
    vector<List> hashTable = createHashTable(A, M);
    printHashTable(hashTable);
    cout << "\n-----------------\n";
    enterHash(hashTable);
    cout << "\n-----------------\n";
    printHashTable(hashTable);
    cout << "\n-----------------\n";
    findHash(hashTable, 27);
    cout << "\n-----------------\n";
    delHash(hashTable, 27);
    printHashTable(hashTable);
}

//Peretz, 11, 10.07.2000, goalkeeper, 1500