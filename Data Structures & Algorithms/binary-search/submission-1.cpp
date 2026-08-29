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
            cout<<"\nums{mid}"<<mid;
            if(target == nums[mid])
            {
                flag=1;
                cout<<"\mid="<<mid;
                return mid;
            }
            if(target<nums[mid])
            {
                end=mid-1;
                cout<<"\nend="<<end;
            }
            else if(target>nums[mid])
            {
                beg=mid+1;
                cout<<"\nbeg="<<beg;
            }
        }

      if(flag==-1)  
      {
        return -1;
      }
    }
};
