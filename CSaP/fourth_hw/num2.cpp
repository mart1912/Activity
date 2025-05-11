#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");


void sh3_stroka(vector<double>& a) {
    int n = a.size();
    
    int step = 1;
    while (step * 3 + 1 < n) {
        step = step * 3 + 1;
    }

    while (step >= 1) {
        for (int i = 0; i < n - step; i++) {
            int j = i;
            while (j >= 0 && a[j] > a[j + step]) {
                swap(a[j], a[j + step]);
                j -= step;
            }
        }
        step = (step - 1) / 3;
    }
}

void ub(vector<double>& row) {
    sh3_stroka(row);
    reverse(row.begin(), row.end());
}

void sh3_matrix(vector<vector<double>>& matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i % 2 == 1) {
            ub(matrix[i]);
        } else {
            sh3_stroka(matrix[i]);
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
    sh3_matrix(matrix);
    vivod(matrix);
    return 0;
}