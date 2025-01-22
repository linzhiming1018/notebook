#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> getLPS(const string &pattern) {
        vector<int> lps(pattern.length());
        for (int i = 1, j = 0; i < pattern.length(); i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = lps[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                j++;
            }
            lps[i] = j;
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        vector<int> lps = getLPS(needle);
        for (int i = 0, j = 0; i < haystack.length(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = lps[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.length()) {
                return i - needle.length() + 1;
            }
        }
        return -1;
    }
};
