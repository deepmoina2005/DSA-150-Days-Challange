#include <iostream>
#include <vector>
#include <unordered_map>  // Correct header for unordered_map

using namespace std;

vector<int> twoSum(vector<int>& arr, int tar) {
    unordered_map<int, int> m;  // Fixed spelling of unordered_map
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {
        int first = arr[i];
        int sec = tar - first;

        if (m.find(sec) != m.end()) {
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;  // Fixed spelling of "break"
        }

        m[first] = i;
    }
    return ans;
}

int main() {
    vector<int> arr = {5, 2, 7, 11, 17, 15};
    int target = 9;

    vector<int> result = twoSum(arr, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}