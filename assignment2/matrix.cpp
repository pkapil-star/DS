#include <iostream>
using namespace std;


class DiagonalMatrix {
    int *arr;
    int n;
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n]; // only store diagonal elements
    }

    void set(int i, int j, int val) {
        if (i == j) arr[i] = val;
    }

    int get(int i, int j) {
        if (i == j) return arr[i];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << arr[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};


class TriDiagonalMatrix {
    int *arr;
    int n;
public:
    TriDiagonalMatrix(int size) {
        n = size;
        arr = new int[3*n - 2]; // store 3 diagonals
    }

    void set(int i, int j, int val) {
        if (i - j == 1) arr[i-1] = val;            // lower diag
        else if (i == j) arr[n - 1 + i] = val;    // main diag
        else if (j - i == 1) arr[2*n - 1 + i] = val; // upper diag
    }

    int get(int i, int j) {
        if (i - j == 1) return arr[i-1];
        else if (i == j) return arr[n - 1 + i];
        else if (j - i == 1) return arr[2*n - 1 + i];
        return 0;
    }
};


class LowerTriangularMatrix {
    int *arr;
    int n;
public:
    LowerTriangularMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2]; // only store lower part
    }

    void set(int i, int j, int val) {
        if (i >= j) arr[i*(i+1)/2 + j] = val;
    }

    int get(int i, int j) {
        if (i >= j) return arr[i*(i+1)/2 + j];
        return 0;
    }
};


class UpperTriangularMatrix {
    int *arr;
    int n;
public:
    UpperTriangularMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2]; // only store upper part
    }

    void set(int i, int j, int val) {
        if (i <= j) arr[j*(j+1)/2 + i] = val;
    }

    int get(int i, int j) {
        if (i <= j) return arr[j*(j+1)/2 + i];
        return 0;
    }
};


class SymmetricMatrix {
    int *arr;
    int n;
public:
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2]; // only store lower part
    }

    void set(int i, int j, int val) {
        if (i >= j) arr[i*(i+1)/2 + j] = val;
        else arr[j*(j+1)/2 + i] = val; // symmetry
    }

    int get(int i, int j) {
        if (i >= j) return arr[i*(i+1)/2 + j];
        else return arr[j*(j+1)/2 + i];
    }
};


int main() {
    cout << "Diagonal Matrix:\n";
    DiagonalMatrix d(4);
    d.set(0,0,1); d.set(1,1,2); d.set(2,2,3); d.set(3,3,4);
    d.display();


    cout << "Tri-diagonal Matrix:\n";
    TriDiagonalMatrix t(4);

    // Main diagonal
    t.set(0,0,1); t.set(1,1,2); t.set(2,2,3); t.set(3,3,4);

    // Upper diagonal
    t.set(0,1,5); t.set(1,2,6); t.set(2,3,7);

    // Lower diagonal
    t.set(1,0,8); t.set(2,1,9); t.set(3,2,10);

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) cout << t.get(i,j) << " ";
        cout << endl;
    }
    // return 0;


    cout << "\nLower Triangular Matrix:\n";
    LowerTriangularMatrix l(3);
    l.set(0,0,1); l.set(1,0,2); l.set(1,1,3); l.set(2,0,4); l.set(2,1,5); l.set(2,2,6);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout << l.get(i,j) << " ";
        cout << endl;
    }


    cout << "Upper Triangular Matrix:\n";
    UpperTriangularMatrix u(3);

    u.set(0,0,1); u.set(0,1,2); u.set(0,2,3);
    u.set(1,1,4); u.set(1,2,5);
    u.set(2,2,6);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout << u.get(i,j) << " ";
        cout << endl;
    }




    cout << "\nSymmetric Matrix:\n";
    SymmetricMatrix s(3);
    s.set(0,0,1); s.set(1,0,2); s.set(1,1,3); s.set(2,0,4); s.set(2,1,5); s.set(2,2,6);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout << s.get(i,j) << " ";
        cout << endl;
    }

    return 0;
}
