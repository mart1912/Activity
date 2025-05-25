#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string flag;
        int a;
        cin >> a;
        vector <int> f(a);
        vector <int> s(a);
        for (int q = 0; q < a; q++) {
            int p;
            cin >> p;
            f[q] = p;
        }
        for (int w = 0; w < a; w++) {
            int g;
            cin >> g;
            s[w] = g;
        }
        vector <int> delt(a);
        for (int d = 0; d < a; d++) {
            delt[d] = f[d] - s[d];
        }
        int maxx = *max_element(begin(delt), end(delt));
        cout << maxx << '\n';
        int k = 0;
        for (int y = 0; y < a; y++) {
            if (s[y] <= f[y]) {
                if (s[y] != 0) {
                    if (f[y] - maxx == s[y])
                        k++;
                }
                else {
                    if (maxx >= f[y] - s[y])
                        k++;
                }
            }
        }
        if (k == a) flag = "YES";
        else flag = "NO";
        cout << flag << '\n';
    }
    return 0;
}