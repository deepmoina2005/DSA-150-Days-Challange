#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // for sort

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        int tar = -nums[i];
        set<int> s;

        for (int j = i + 1; j < n; j++) {
            int third = tar - nums[j];

            if (s.find(third) != s.end()) {
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }

            s.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(arr);

    if (!result.empty()) {
        cout << "Triplets that sum to 0:\n";
        for (const auto& triplet : result) {
            cout << "[";
            for (int i = 0; i < triplet.size(); ++i) {
                cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
            }
            cout << "]\n";
        }
    } else {
        cout << "No triplets found that sum to 0." << endl;
    }

    return 0;
}