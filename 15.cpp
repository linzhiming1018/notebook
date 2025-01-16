#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> n1 = {-1, 0, 1, 2, -1, -4};
    vector<int> n2 = {-2, 0, 0, 2, 2};
    vector<vector<int> > a1 = solution.threeSum(n1);
    vector<vector<int> > a2 = solution.threeSum(n2);
    return 0;
}
