#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

struct date{//дата
    int dd, mm, yy;
};

struct people{//данные о человеке
    string Surname; //фамилия
    string Post; //должность
    date DateOfBirth; //дата рождения
    int Experience; //стаж
    int Salary; //зарплата
};

date Str_to_Date(string str){//из строки в дату
    date x;
    string temp = str.substr(0, 2);//день
    x.dd = atoi(temp.c_str()) ;
    temp = str.substr(3, 2);//месяц
    x.mm = atoi(temp.c_str());
    temp = str.substr(6, 4);//год
    x.yy = atoi(temp.c_str()) ;
    return x;
}

vector<people> inFile(){//ввод из файла
    vector<people> x;
    people temp;
    while(in.peek() != EOF){
        in >> temp.Surname;//фамилия
        in >> temp.Post;//должность
        string tmp;//дата рождения
        in >> tmp;
        temp.DateOfBirth = Str_to_Date(tmp);
        in >> temp.Experience;//стаж
        in >> temp.Salary;//зарплата
        x.push_back(temp);
    }
    return x;
}

void print(people x){//вывод в файл
    out << setw(10) << left << x.Surname;//по левому краю, 10 позиций для фамилии
    out << setw(15) << left << x.Post;//по левому краю, 15 позиций для должности
    if (x.DateOfBirth.dd < 10) out << left << '0' << x.DateOfBirth.dd << '.';//добавляем 0
    else out << left << x.DateOfBirth.dd << '.';
    if (x.DateOfBirth.mm < 10) out << '0' << x.DateOfBirth.mm << '.';
    else out << x.DateOfBirth.mm << '.';
    out << left << setw(6) << x.DateOfBirth.yy;//на год 6 позиций
    out << left << setw(3) << x.Experience;//на стаж 3 позиции
    out << left << setw(5) << x.Salary << endl;//запрлата
}

bool operator < (people a, people b){//переопределяем оператор < в соотвествии с условием
    if (a.Salary < b.Salary) return true;
    if (a.Salary == b.Salary && a.DateOfBirth.yy < b.DateOfBirth.yy) return true;
    if (a.Salary == b.Salary && a.DateOfBirth.yy == b.DateOfBirth.yy && a.Experience < b.Experience) return true;
    return false;
}

void choice(vector<people>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

int main(){
    vector<people> x;
    x = inFile();
    choice(x);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}