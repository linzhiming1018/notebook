#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> s(nums1.cbegin(), nums1.cend());
        unordered_set<int> ans;
        for (auto &i: nums2) {
            if (s.find(i) != s.cend())
                ans.emplace(i);
        }
        return vector<int>(ans.cbegin(), ans.cend());
    }
};

int main() {
    return 0;
}
