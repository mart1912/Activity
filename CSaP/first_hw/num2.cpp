#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a;
    int q;
    for (int i = 0; i < n; i++) {cin >> q; a.push_back(q);}

    vector<int> a1 = a;
    reverse(a1.begin(), a1.end());
    for(vector<int>::iterator iter = a1.begin(); iter != a1.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    vector<int> a2 = a;
    int A, B, X;
    cin >> A >> B >> X;
    for (vector<int>::iterator iter = a2.begin(); iter != a2.end(); iter++)
        if (*iter >= A && *iter <= B) *iter = X;
    for (vector<int>::iterator iter = a2.begin(); iter != a2.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    vector<int> a3 = a;
    sort(a3.begin(), a3.end());
    int x;
    cin >> x;
    vector<int>::iterator iter = lower_bound(a3.begin(), a3.end(), x);
    a3.insert(iter, x);
    for (auto num : a3) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> a4 = a;
    sort(a4.begin(), a4.end());
    vector<int>::iterator un = unique(a4.begin(), a4.end());
    a4.erase(un, a4.end());
    for (auto num : a4) {
        cout << num << " ";
    }
    cout << endl;
}