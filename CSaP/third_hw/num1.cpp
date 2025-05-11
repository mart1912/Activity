#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>
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

void lsd_sort(vector<people> &a){//поразрядная сортировка
    if (a.empty()) return;

    int k = 5;
    vector<people> temp(a.size());

    for (int i = 0; i < k; ++i) {
        vector<int> count(10, 0);

        for (const auto& p : a) {
            int digit = (p.Salary / (int)pow(10, i)) % 10;
            count[digit]++;
        }

        for (int j = 1; j < 10; ++j) {
            count[j] += count[j - 1];
        }

        for (int j = a.size() - 1; j >= 0; --j) {
            int digit = (a[j].Salary / (int)pow(10, i)) % 10;
            temp[count[digit] - 1] = a[j];
            count[digit]--;
        }

        a = temp;
    }
}

int main(){
    vector<people> x;
    x = inFile();
    lsd_sort(x);
    for (int i = 0; i < x.size(); i++)
        print(x[i]);
    return 0;
}