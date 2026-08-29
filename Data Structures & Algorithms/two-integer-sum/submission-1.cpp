class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If complement is found, return original index and current index
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            
            // Store current value and its index
            seen[nums[i]] = i;
        }
        
        return {};
    }
};