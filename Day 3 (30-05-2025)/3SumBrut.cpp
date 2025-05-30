#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // for sort

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> s;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end()); // To ensure uniqueness
                    if(s.find(trip) == s.end()) {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }

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