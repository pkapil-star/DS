#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int nums[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[nums[i]]++;

    int ans = -1;
    for (int i = 0; i < n; i++)
        if (freq[nums[i]] == 1) {
            ans = nums[i];
            break;
        }

    if (ans == -1) cout << "No non-repeating element";
    else cout << ans;

    return 0;
}
