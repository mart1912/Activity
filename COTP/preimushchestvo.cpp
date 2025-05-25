#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int j = 0; j < n; j++) {
            int s;
            cin >> s;
            a[j] = s;
        }
        vector <int> max(n);
        vector <int> ans(n);
        for (int p = 0; p < n; p++) {
            for (int i = 0; i < n; i++) {
                if (p != i) {
                    if (max[p] < a[i]) max[p] = a[i];
                }
            }
            ans[p] = a[p] - max[p];
        }
        for (int b = 0; b < n; b++) {
            cout << ans[b] << " ";
        }
        cout << '\n';
    }
    return 0;
}