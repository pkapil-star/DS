#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements:\n";
    for(int i=0;i<n;i++) cin >> arr[i];

    set<int> distinct;
    for(int i=0;i<n;i++) distinct.insert(arr[i]);

    cout << "Total distinct elements: " << distinct.size() << endl;
    return 0;
}
