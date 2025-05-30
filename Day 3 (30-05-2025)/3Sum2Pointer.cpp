#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // for sort

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i<n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1, k = n-1;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0){
                j++;
            } else if(sum > 0){
                k--;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while(j < k && nums[j] == nums[j - 1]) j++;
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