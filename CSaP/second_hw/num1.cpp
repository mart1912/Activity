#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>
#include <string>
using namespace std;
int main() {
    set <int> a; // множество чисел из условия
    int n = 10;
    int r;
    for(int i = 0; i < n; i++){cin >> r; a.insert(r);}

    string q;
    for(set<int>::iterator iter = a.begin(); iter != a.end(); iter++){q += to_string(*iter);}
    string q2;
    for(set<int>::iterator iter = a.begin(); iter != a.end(); iter++){if (*iter > 9 && *iter < 100) q2 += to_string(*iter);}
    
    set <int> d; // множество цифр, из которых состоят все числа
    for(auto el : q) {d.insert(el - '0');}
    set <int> d2; // множество цифр, из которых состоят двузначные числа
    for(auto el2 : q2) {d2.insert(el2 - '0');}
    
    set <int> ans;
    set_difference(d.begin(), d.end(), d2.begin(), d2.end(), inserter(ans, ans.begin()));
 
    for(set<int>::iterator i = d2.begin(); i != d2.end(); ++i)
        cout << *i << " ";
    cout << endl;
    for(set<int>::iterator i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";
    cout << endl;
    return 0;
}
// 14 5 3 356 16 18 88 3 98 929