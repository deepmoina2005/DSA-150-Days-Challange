// Brute Force Solution for Container With Most Water Problem
#include <iostream>
#include <vector>
#include <algorithm> // for min() and max()

using namespace std;

int maxArea(vector<int>& height) {
    int maxWater = 0;

    for (int i = 0; i < height.size(); i++) {
        for (int j = i + 1; j < height.size(); j++) {
            int width = j - i;
            int ht = min(height[i], height[j]);
            int currentWater = width * ht;
            maxWater = max(maxWater, currentWater);
        }
    }

    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Maximum water container area: " << maxArea(height) << endl;
    return 0;
}
