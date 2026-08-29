class Solution {
public:
    int trap(vector<int>& height) {

        if(height.empty())
        {
            return 0;
        }
        int n=height.size();
        int res=0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0]=height[0];
        for(int j=1;j<n;j++)
            {
                leftMax[j]=max(leftMax[j-1],height[j]);
            }

        rightMax[n-1]=height[n-1];
        for(int j=n-2;j>=0;j--)
            {
                rightMax[j]=max(rightMax[j+1],height[j]);
            }
        for(int i=0;i<n;i++)
        {
        res+= min(leftMax[i],rightMax[i])-height[i];
        }
        

        return res;
        
    }
};
