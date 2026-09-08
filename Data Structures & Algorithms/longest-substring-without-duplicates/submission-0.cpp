#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> visited;
        int front = 0;
        int back = 0;
        int longest = 0;
        
        while (back < s.length()) {
            if (visited.find(s[back]) == visited.end()) {
                visited.insert(s[back]);
                longest = std::max(longest, back - front + 1);
                back++;
            } else {
                visited.erase(s[front]);
                front++;
            }
        }
        
        return longest;
    }
};