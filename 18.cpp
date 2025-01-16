#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    long long sum_1 = nums[i] + nums[j];
                    long long sum_2 = nums[l] + nums[r];
                    if (sum_2 < target - sum_1)
                        ++l;
                    else if (sum_2 > target - sum_1)
                        --r;
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) ++l;
                        while (l < r && nums[r] == nums[r - 1]) --r;
                        ++l;
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000};
    vector<vector<int> > ans = s.fourSum(nums, -294967296);
    return 0;
}
