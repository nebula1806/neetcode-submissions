#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> count(26, 0);
        
        int l = 0;
        int max_count = 0;
        int max_len = 0;
        
        for (int r = 0; r < s.length(); r++) {
            count[s[r] - 'A']++;
            
            max_count = std::max(max_count, count[s[r] - 'A']);
            
            while ((r - l + 1) - max_count > k) {
                count[s[l] - 'A']--;
                l++;
            }
            
            max_len = std::max(max_len, r - l + 1);
        }
        
        return max_len;
    }
};