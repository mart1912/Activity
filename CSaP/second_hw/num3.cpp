#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    set<string> pov, vopr, vosk;
    string razd = "?!.";
    string razd2 = "?!. ";
    string text;
    getline(cin, text);
    size_t pos = 0;
    size_t k = text.find_first_of(razd, pos);
    while (k != string::npos) {
        string temp = text.substr(pos,k - pos + 1);
        size_t pos1 = 0;
        size_t k1 = temp.find_first_of(razd2, pos1);
        while (k1 != string::npos) {
            string word = temp.substr(pos1,k1 - pos1);
            for (int i = 0; i < word.size(); i++) {
                if (isupper(word[i])) {
                    word[i] = tolower(word[i]);
                }
            }
            switch (text[k]) {
                case '?': vopr.insert(word); break;
                case '.': pov.insert(word); break;
                case '!': vosk.insert(word); break;
            };
            pos1 = k1 + 1;
            k1 = temp.find_first_of(razd2, pos1);
        }
        pos = k + 2;
        k = text.find_first_of(razd, pos);
    }
    vector<string> res;
    set_intersection(pov.begin(), pov.end(), vosk.begin(), vosk.end(),inserter(res, res.begin()));
    for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << '\n';
}
//Did you go anywhere today? I went to the store, to the park and walked to the border with Serbia. I walked to the border with Serbia! And where were you? Well, I went to the store today!