#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

void vstavki(vector<double>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

vector<double> block_stroka(const vector<double>& row) {
    int p = (int)row.size() / 2;

    double min_val = *min_element(row.begin(), row.end());
    double max_val = *max_element(row.begin(), row.end());

    vector<vector<double>> buckets(p);
    double m = (max_val - min_val) / p;
    for (double num : row) {
        int k = (int)((num - min_val) / m);
        if (k == p) k = p - 1;
        buckets[k].push_back(num);
    }

    for (auto& bucket : buckets) {
        vstavki(bucket);
    }

    vector<double> sorted_row;
    for (auto it = buckets.rbegin(); it != buckets.rend(); ++it) {
        sorted_row.insert(sorted_row.end(), it->begin(), it->end());
    }

    return sorted_row;
}

vector<vector<double>> block_matrix(const vector<vector<double>>& matrix) {
    vector<vector<double>> sorted_matrix;
    for (const auto& row : matrix) {
        sorted_matrix.push_back(block_stroka(row));
    }
    return sorted_matrix;
}

void vivod(const vector<vector<double>>& matrix) {
    ofstream out("output.txt");
    for (const auto& row : matrix) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) out << " ";
            out << row[i];
        }
        out << endl;
    }
}

int main() {
    ifstream in("input.txt");
    int n = 7;
    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> matrix[i][j];
        }
    }
    vector<vector<double>> sorted_matrix = block_matrix(matrix);
    vivod(sorted_matrix);
    return 0;
}
