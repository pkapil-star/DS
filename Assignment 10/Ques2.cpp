#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cout << "Enter size of A: ";
    cin >> n;
    int A[n];
    cout << "Enter elements of A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Enter size of B: ";
    cin >> m;
    int B[m];
    cout << "Enter elements of B: ";
    for (int i = 0; i < m; i++) cin >> B[i];

    unordered_set<int> setA;
    for (int i = 0; i < n; i++)
        setA.insert(A[i]);

    cout << "Common elements: ";
    for (int i = 0; i < m; i++)
        if (setA.find(B[i]) != setA.end())
            cout << B[i] << " ";

    return 0;
}
