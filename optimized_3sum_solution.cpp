#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            int n = nums.size();
            // sort vector
            sort(nums.begin(), nums.end());  

            for (int i = 0; i < n - 2; ++i) {
                // Skip duplicate elements
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;

                int target = -nums[i];
                int left = i + 1;
                int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

    return result;
    }
};

// function to generate a random array with at least one valid triplet
vector<int> generateRandomArray(int size) {
    vector<int> nums(size);
    
    // generating random values between -size/2 and size/2
    for (int i = 0; i < size; i++) {
        nums[i] = rand() % (size) - size / 2;
    }
    
    // ensure at least one valid triplet, e.g., -a, -b, a+b
    int a = rand() % (size / 2) - size / 4;
    int b = rand() % (size / 2) - size / 4;
    nums.push_back(-a);
    nums.push_back(-b);
    nums.push_back(a + b);
    
    return nums;
}

int main() {
    Solution solution;
    
    srand(time(0));

    vector<int> sizes = {100, 200, 300, 400, 500, 600, 700, 800};
    
    for (int size : sizes) {
        // generate random input array
        vector<int> nums = generateRandomArray(size);

        // measure execution time of threeSum
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = solution.threeSum(nums);
        auto end = chrono::high_resolution_clock::now();

        // calculate duration in milliseconds
        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

        // output result
        cout << "Array size: " << size << " | Time: " << time_ms << " ms" << endl;
    }

    return 0;
}