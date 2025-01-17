#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > ans;
        // 1 <= nums.size() <= 200
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            // Pruning
            if (nums[i] >= 0 && nums[i] > target / 4)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                // Pruning
                if (nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target / 2)
                    break;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    long long sum_1 = nums[i] + nums[j];
                    long long sum_2 = nums[l] + nums[r];
                    if (sum_2 < target - sum_1) ++l;
                    else if (sum_2 > target - sum_1) --r;
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
    vector<int> n1 = {1000000000, 1000000000, 1000000000, 1000000000};
    vector<vector<int> > a1 = s.fourSum(n1, -294967296);
    vector<int> n2 = {1000000000, 1000000000, 1000000000, 1000000000};
    vector<vector<int> > a2 = s.fourSum(n1, 0);
    vector<int> n3 = {-3, -2, -1, 0, 0, 1, 2, 3};
    vector<vector<int> > a3 = s.fourSum(n3, 0);
    vector<int> n4 = {1, -2, -5, -4, -3, 3, 3, 5};
    vector<vector<int> > a4 = s.fourSum(n4, -11);
    return 0;
}
