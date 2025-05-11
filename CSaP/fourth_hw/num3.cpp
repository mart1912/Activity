#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

void choice_stroka(vector<double>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

void ub(vector<double>& a) {
    choice_stroka(a);
    reverse(a.begin(), a.end());
}

void choice_matrix(vector<vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // выше главной
    for (int k = 1; k < cols; ++k) {
        vector<double> diagonal;
        for (int i = 0, j = k; i < rows && j < cols; ++i, ++j) {
            diagonal.push_back(matrix[i][j]);
        }
        ub(diagonal);
        for (int i = 0, j = k, idx = 0; i < rows && j < cols; ++i, ++j, ++idx) {
            matrix[i][j] = diagonal[idx];
        }
    }

    // ниже главной
    for (int k = 1; k < rows; ++k) {
        vector<double> diagonal;
        for (int i = k, j = 0; i < rows && j < cols; ++i, ++j) {
            diagonal.push_back(matrix[i][j]);
        }
        ub(diagonal);
        for (int i = k, j = 0, idx = 0; i < rows && j < cols; ++i, ++j, ++idx) {
            matrix[i][j] = diagonal[idx];
        }
    }
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

int main(){
    ifstream in("input.txt");
    int n = 7;
    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> matrix[i][j];
        }
    }
    choice_matrix(matrix);
    vivod(matrix);
    return 0;
}