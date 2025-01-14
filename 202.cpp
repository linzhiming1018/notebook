#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (true) {
            int sum = 0;
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (sum == 1) return true;
            else if (s.find(sum) != s.cend()) return false;
            else {
                s.emplace(sum);
                n = sum;
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19);
    return 0;
}
