#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        unordered_map<char, int> um;
        for (const char &i: magazine) {
            auto iter = um.find(i);
            if (iter != um.cend()) {
                iter->second++;
            } else um.emplace(i, 1);
        }
        for (const char &i: ransomNote) {
            auto iter = um.find(i);
            if (iter != um.cend() && iter->second > 0) {
                iter->second--;
            } else return false;
        }
        return true;
    }
};
