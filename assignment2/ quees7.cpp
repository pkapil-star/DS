#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(vector<int> &arr, int left, int mid, int right) {
    vector<int> L(arr.begin()+left, arr.begin()+mid+1);
    vector<int> R(arr.begin()+mid+1, arr.begin()+right+1);

    int i=0, j=0, k=left;
    long long invCount=0;

    while(i<L.size() && j<R.size()) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            invCount += (L.size()-i); // all remaining in L are greater than R[j]
        }
    }
    while(i<L.size()) arr[k++] = L[i++];
    while(j<R.size()) arr[k++] = R[j++];
    return invCount;
}

long long mergeSortAndCount(vector<int> &arr, int left, int right) {
    long long invCount=0;
    if(left < right) {
        int mid = left + (right-left)/2;
        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid+1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for(int i=0;i<n;i++) cin >> arr[i];

    long long invCount = mergeSortAndCount(arr, 0, n-1);
    cout << "Number of inversions: " << invCount << endl;
    return 0;
}
