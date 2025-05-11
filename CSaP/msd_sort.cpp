// Поразрядная сортировка от старшего разряда к младшему
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void msd_sort(vector<int>& arr, int left, int right, int digit_pos) {
    if (left >= right || digit_pos < 0) return;

    int p = 10;
    vector<vector<int>> buckets(p);

    for (int i = left; i <= right; ++i) {
        int digit = (arr[i] / int(pow(p, digit_pos))) % p;
        buckets[digit].push_back(arr[i]);
    }

    int idx = left;
    for (int j = 0; j < p; ++j) {
        for (const auto& num : buckets[j]) {
            arr[idx++] = num;
        }
    }

    idx = left;
    for (int j = 0; j < p; ++j) {
        int group_size = buckets[j].size();
        if (group_size > 1) {
            msd_sort(arr, idx, idx + group_size - 1, digit_pos - 1);
        }
        idx += group_size;
    }
}

void porazrad_sort_MSD(vector<int>& x) {
    if (x.empty()) return;

    int max_num = x[0];
    for (const auto num : x) {
        if (num > max_num) max_num = num;
    }

    int k = 0;
    while (max_num != 0) {
        max_num /= 10;
        ++k;
    }

    msd_sort(x, 0, x.size() - 1, k - 1);
}

int main() {
    vector<int> x = {3456, 23, 54645, 24, 6345, 243, 75683, 294, 9023, 332, 6, 89};
    porazrad_sort_MSD(x);
    for (int num : x) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}