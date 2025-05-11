#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <map>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    string num = "0123456789";
    ifstream in("input.txt");
    string s;
    getline(in, s);
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = s.find(" ")) != string::npos) {
        token = s.substr(0, pos);
        if (token.find_first_of(num)) tokens.push_back(token);
        s.erase(0, pos + 1);
    }
    if (s.find_first_of(num)) tokens.push_back(s);
    vector <int> counts;
    for (int i = 0; i < tokens.size(); i++)
        counts.push_back(count(tokens.begin(), tokens.end(), tokens[i])); 
    map<string, int> a;
    for (int i = 0; i < tokens.size(); i++) {
        a.insert({tokens[i], counts[i]});
    }
    multimap<int, string> b;
    for (auto pair : a) {
        b.insert({pair.second, pair.first});
    }
    cout << "----------------------\n";
    for (auto pair : b) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "----------------------\n";
    int k = 0;
    int p;
    cin >> p;
    if (p > b.size()) {cout << "В строке нет столько слов"; goto end;}
    for (auto pair : b) {
        if (k < p) {
            cout << pair.second << endl;
            k++;
        }
    }
    end:
    cout << endl;
    return 0;
}
//qwerty asjif 677 vv asjif vv 87 vv vv 3562 vv qwerty 77 asjif 7 bysdycb yv yv vv 9 nnnnn asjif bysdycb nnnnn