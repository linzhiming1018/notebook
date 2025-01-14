#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSumBruteForce(std::vector<int> &nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans.emplace_back(i);
                    ans.emplace_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }

    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = m.find(target - nums[i]);
            if (iter != m.cend()) {
                return {iter->second, i};
            }
            m.emplace(nums[i], i);
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 4};
    vector<int> ans = s.twoSum(nums, 6);
    for (const auto &i: ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
