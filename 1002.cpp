#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &words) {
        vector<int> minFreq(26, 0x7fffffff);
        for (auto &word: words) {
            vector<int> freq = vector<int>(26, 0);
            for (int i = 0; i < word.length(); i++) {
                freq[word[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++)
                minFreq[i] = (freq[i] < minFreq[i]) ? freq[i] : minFreq[i];
        }
        vector<string> ans = vector<string>();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < minFreq[i]; j++)
                ans.emplace_back(1, 'a' + i);
        }
        return ans;
    }
};

int main() {
    vector<string> words = {"bella", "label", "roller"};
    Solution solution;
    vector<string> res = solution.commonChars(words);
    for (string &s: res) {
        printf("%s\n", s.c_str());
    }
    return 0;
}
