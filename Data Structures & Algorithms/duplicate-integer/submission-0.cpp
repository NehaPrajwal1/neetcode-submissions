class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seeing;
        for(int n:nums)
        {
            if(seeing.count(n))
            {
                return true;
            }
            seeing.insert(n);
        }
        return false;
    }
};