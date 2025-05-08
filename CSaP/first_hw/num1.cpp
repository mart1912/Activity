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
    int min = *min_element(a.begin(), a.end());
    int k = count(a.begin(), a.end(), min);
    cout << k << endl;
}