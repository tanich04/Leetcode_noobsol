class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Find the minimum length string
        size_t min_length = std::min_element(strs.begin(), strs.end(), 
            [](const std::string& a, const std::string& b) {
                return a.size() < b.size();
            })->size();
        
        std::string prefix;
        
        for (size_t i = 0; i < min_length; ++i) {
            char current_char = strs[0][i];
            for (const std::string& str : strs) {
                if (str[i] != current_char) {
                    return prefix; // Return prefix found so far
                }
            }
            prefix += current_char;
        }
        
        return prefix;
    }
};