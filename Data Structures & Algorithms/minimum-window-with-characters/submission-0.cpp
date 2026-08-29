class Solution {
public:
    string minWindow(string s, string t) {


    if (t.size() > s.size()) return ""; 
 
    vector<int> freq(128, 0); 
 
    // Store required character frequencies 
    for (char c : t) { 
        freq[c]++; 
    } 
 
    int left = 0; 
    int right = 0; 
 
    int required = t.size(); 
    int minLen = INT_MAX; 
    int start = 0; 
 
    while (right < s.size()) { 
 
        // Include s[right] in the window 
        if (freq[s[right]] > 0) { 
            required--; 
        } 
 
        freq[s[right]]--; 
        right++; 
 
        // Window contains all characters of t 
        while (required == 0) { 
 
            // Update minimum window 
            if (right - left < minLen) { 
                minLen = right - left; 
                start = left; 
            } 
 
            // Remove s[left] 
            freq[s[left]]++; 
 
            if (freq[s[left]] > 0) { 
                required++; 
            } 
 
            left++; 
        } 
    } 
 
    return minLen == INT_MAX ? "" : s.substr(start, minLen); 



        
    }
};
