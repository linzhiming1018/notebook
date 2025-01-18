#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int slow = 0;
        int fast = 0;
        // Skip leading spaces
        while (fast < s.length() && s[fast] == ' ') {
            ++fast;
        }
        while (fast < s.length()) {
            if (fast > 0 && s[fast] == ' ' && s[fast] == s[fast - 1]) {
                ++fast;
            } else {
                s[slow++] = s[fast++];
            }
        }
        // Remove trailing spaces
        if (slow > 0 && s[slow - 1] == ' ') {
            --slow;
        }
        s.resize(slow);
        reverse(s.begin(), s.end());
        for (auto begin = s.begin(); begin != s.end();) {
            auto end = find(begin, s.end(), ' ');
            reverse(begin, end);
            begin = (end != s.end()) ? ++end : s.end();
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "the sky is blue";
    s = solution.reverseWords(s);
    cout << s << endl;
    return 0;
}
