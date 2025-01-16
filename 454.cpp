#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(std::vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int count = 0;
        unordered_map<int, int> um;
        for (const int &i: nums1) {
            for (const int &j: nums2) {
                um[i + j]++;
            }
        }
        for (const int &i: nums3) {
            for (const int &j: nums4) {
                if (um.find(-i - j) != um.cend()) {
                    count += um.find(-i - j)->second;
                }
            }
        }
        return count;
    }
};
