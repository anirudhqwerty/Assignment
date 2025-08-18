#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and cols of first matrix: ";
    cin >> r1 >> c1;
    int A[r1][c1];
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter rows and cols of second matrix: ";
    cin >> r2 >> c2;
    int B[r2][c2];
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    cout << endl << "Transpose of first matrix:" << endl;
    for (int j = 0; j < c1; j++) {
        for (int i = 0; i < r1; i++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    if (r1 == r2 && c1 == c2) {
        cout << endl << "Addition A + B:" << endl;
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                cout << A[i][j] + B[i][j] << " ";
            }
            cout << endl;
        }
    }

    if (c1 == r2) {
        cout << endl << "Multiplication A * B:" << endl;
        int C[r1][c2];
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                C[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
                cout << C[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
