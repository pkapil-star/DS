#include <iostream>
using namespace std;

// Structure to hold sparse matrix in triplet form
struct SparseMatrix {
    int rows, cols, nonZero;
    int **data; // 2D array: [nonZero+1][3] (row, col, value)

    // Constructor
    SparseMatrix(int r, int c, int nz) {
        rows = r; cols = c; nonZero = nz;
        data = new int*[nz+1];
        for (int i = 0; i <= nz; i++)
            data[i] = new int[3];
        data[0][0] = r;
        data[0][1] = c;
        data[0][2] = nz;
    }

    // Input non-zero values
    void input() {
        cout << "Enter row col value for " << nonZero << " non-zero elements:\n";
        for (int i = 1; i <= nonZero; i++) {
            cin >> data[i][0] >> data[i][1] >> data[i][2];
        }
    }

    // Display triplet form
    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i <= nonZero; i++) {
            cout << data[i][0] << " " << data[i][1] << " " << data[i][2] << endl;
        }
    }
};

// (a) Transpose
SparseMatrix transpose(SparseMatrix &m) {
    SparseMatrix t(m.cols, m.rows, m.nonZero);
    int k = 1;
    for (int c = 0; c < m.cols; c++) {
        for (int i = 1; i <= m.nonZero; i++) {
            if (m.data[i][1] == c) {
                t.data[k][0] = m.data[i][1];
                t.data[k][1] = m.data[i][0];
                t.data[k][2] = m.data[i][2];
                k++;
            }
        }
    }
    return t;
}

// (b) Addition
SparseMatrix add(SparseMatrix &a, SparseMatrix &b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Matrices dimensions do not match!\n";
        return SparseMatrix(0,0,0);
    }
    SparseMatrix sum(a.rows, a.cols, 0);
    int i=1, j=1, k=1;

    while (i <= a.nonZero && j <= b.nonZero) {
        if (a.data[i][0] < b.data[j][0] ||
            (a.data[i][0]==b.data[j][0] && a.data[i][1] < b.data[j][1])) {
            sum.data[k][0] = a.data[i][0];
            sum.data[k][1] = a.data[i][1];
            sum.data[k][2] = a.data[i][2];
            i++; k++;
        }
        else if (b.data[j][0] < a.data[i][0] ||
                 (a.data[i][0]==b.data[j][0] && b.data[j][1] < a.data[i][1])) {
            sum.data[k][0] = b.data[j][0];
            sum.data[k][1] = b.data[j][1];
            sum.data[k][2] = b.data[j][2];
            j++; k++;
        }
        else { // same position
            sum.data[k][0] = a.data[i][0];
            sum.data[k][1] = a.data[i][1];
            sum.data[k][2] = a.data[i][2] + b.data[j][2];
            i++; j++; k++;
        }
    }
    while (i <= a.nonZero) {
        sum.data[k][0] = a.data[i][0];
        sum.data[k][1] = a.data[i][1];
        sum.data[k][2] = a.data[i][2];
        i++; k++;
    }
    while (j <= b.nonZero) {
        sum.data[k][0] = b.data[j][0];
        sum.data[k][1] = b.data[j][1];
        sum.data[k][2] = b.data[j][2];
        j++; k++;
    }

    sum.nonZero = k-1;
    sum.data[0][0] = a.rows;
    sum.data[0][1] = a.cols;
    sum.data[0][2] = sum.nonZero;
    return sum;
}

// (c) Multiplication
SparseMatrix multiply(SparseMatrix &a, SparseMatrix &b) {
    if (a.cols != b.rows) {
        cout << "Incompatible matrices for multiplication!\n";
        return SparseMatrix(0,0,0);
    }
    // Convert b to transpose for easier matching
    SparseMatrix bt = transpose(b);

    int temp[100][3]; // temp storage
    int k = 0;

    for (int i = 1; i <= a.nonZero; i++) {
        for (int j = 1; j <= bt.nonZero; j++) {
            if (a.data[i][1] == bt.data[j][1]) {
                int row = a.data[i][0];
                int col = bt.data[j][0];
                int val = a.data[i][2] * bt.data[j][2];

                // check if already exists
                bool found = false;
                for (int x = 0; x < k; x++) {
                    if (temp[x][0] == row && temp[x][1] == col) {
                        temp[x][2] += val;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    temp[k][0] = row;
                    temp[k][1] = col;
                    temp[k][2] = val;
                    k++;
                }
            }
        }
    }

    SparseMatrix prod(a.rows, b.cols, k);
    for (int i = 0; i < k; i++) {
        prod.data[i+1][0] = temp[i][0];
        prod.data[i+1][1] = temp[i][1];
        prod.data[i+1][2] = temp[i][2];
    }
    return prod;
}

int main() {
    int r, c, nz;

    // Input first sparse matrix
    cout << "Enter rows, cols, non-zero count for matrix A: ";
    cin >> r >> c >> nz;
    SparseMatrix A(r,c,nz);
    A.input();
    cout << "Matrix A (Triplet):\n"; A.display();

    // (a) Transpose
    cout << "\nTranspose of A:\n";
    SparseMatrix AT = transpose(A);
    AT.display();

    // Input second sparse matrix for addition and multiplication
    cout << "\nEnter rows, cols, non-zero count for matrix B: ";
    cin >> r >> c >> nz;
    SparseMatrix B(r,c,nz);
    B.input();
    cout << "Matrix B (Triplet):\n"; B.display();

    // (b) Addition
    cout << "\nA + B:\n";
    SparseMatrix SUM = add(A,B);
    SUM.display();

    // (c) Multiplication
    cout << "\nA * B:\n";
    SparseMatrix PROD = multiply(A,B);
    PROD.display();

    return 0;
}
