#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector <int> pr(n + 1);
    for (int i = 0; i < n; i++)
        pr[i + 1] = max(pr[i], a[i]);
    vector <int> su(n + 1);
    for (int i = n - 1; i >= 0; i--)
        su[i] = max(su[i + 1], a[i]);
    for (int i = 0; i < n; i++){
        int mx = max(pr[i], su[i + 1]);
        cout << a[i] - mx << " ";
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
