#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    vector<string> words {"hypothesis", "government", "improvisation", "footballer", "employment", "knowledge",
        "journalist", "verification", "cosmonaut", "application", "territory", "relationship"};
    vector<char> ealph {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> alph = ealph;
    srand(time(0));
    int qw = rand()%words.size();
    string a = words[qw];
    vector <char> ans;
    for (int i = 0; i < a.size(); i++) ans.push_back(a[i]);
    string flag = "true";
    int p = 5;
    cout << "Вам дано 5 попыток отгадать загаданное слово\n";
    vector <char> word;
    for (int i = 0; i < ans.size(); i++) word.push_back('_');
    while (flag == "true") {
        cout << "Отгадать слово целиком - 1, ввести букву - 2\n";
        int k;
        cin >> k;
        if (k == 1) {
            string l;
            cout << "Введите слово: ";
            cin >> l;
            if (l == a) cout << "Вы выиграли!\n";
            else {
                cout << "Вы проиграли, было загадано слово ";
                for (int i = 0; i < ans.size(); i++) cout << ans[i];
                cout << '\n';
            }
            flag = "false";
        }
        else if (k == 2) {
            for (auto i : word) cout << i;
            cout << '\n';
            for (auto i : ealph) cout << i << " ";
            cout << '\n';
            cout << "Введите букву: ";
            char c;
            cin >> c;
            if (count(ealph.begin(), ealph.end(), c) > 0) 
                ealph.erase(find(ealph.begin(), ealph.end(), c));
            else if (count(alph.begin(), alph.end(), c) > 0) {
                while (count(ealph.begin(), ealph.end(), c) == 0) {
                    cout << "Вы уже вводили эту букву, введите другую из предложенных:\n";
                    for (auto j : ealph) cout << j << " "; cout << '\n';
                    cin >> c;
                }
            }
            else {
                while (count(ealph.begin(), ealph.end(), c) == 0) {
                    cout << "Этот символ нельзя вводить, введите другую из предложенных:\n";
                    for (auto j : ealph) cout << j << " "; cout << '\n';
                    cin >> c;
                }
            }
            int f = 0;
            for (int i = 0; i < count(ans.begin(), ans.end(), c); i++) {
                for (int i = 0; i < ans.size(); i++){
                    if (ans[i] == c) {
                        f++;
                        if (f == 1) cout << "Есть такая буква, теперь слово выглядит вот так:\n";
                        word[i] = c;
                    }
                }
                if (i == 0) for (auto j : word) cout << j; cout << '\n';
            }
            if (word == ans) {
                flag = "false";
                cout << "Вы выиграли!" << '\n';
                break;
            }
            if (f == 0) {
                cout << "Буква не найдена!\n";
                p--;
                cout << "Оставшиеся ходы: " << p << '\n';
            }
            if (p == 0) {
                cout << "Вы проиграли, было загадано слово ";
                for (int i = 0; i < ans.size(); i++) cout << ans[i];
                cout << '\n';
                flag = "false";
                break;
            }
        }
    }
    return 0;
}