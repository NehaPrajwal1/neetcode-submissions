class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int mid;
        int beg=0;
        int flag=-1;
        int end=n-1;


        while(beg<=end)
        {
            mid=(beg+end)/2;
         
            if(target == nums[mid])
            {
                flag=1;
                mid;
                return mid;
            }
            if(target<nums[mid])
            {
                end=mid-1;
                
            }
            else if(target>nums[mid])
            {
                beg=mid+1;
                
            }
        }

      if(flag==-1)  
      {
        return -1;
      }
    }
};
