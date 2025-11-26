#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int nums[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_set<int> s;
    bool duplicate = false;

    for (int i = 0; i < n; i++) {
        if (s.find(nums[i]) != s.end()) {
            duplicate = true;
            break;
        }
        s.insert(nums[i]);
    }

    if (duplicate) cout << "true";
    else cout << "false";

    return 0;
}
