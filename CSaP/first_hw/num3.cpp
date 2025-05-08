#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a;
    int q;
    for (int i = 0; i < n; i++) a.push_back(i + 1);

    double ans;
    ans = accumulate(a.begin(), a.end(), 1000., divides<double>());
    cout << ans << endl;
}