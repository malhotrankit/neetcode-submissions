class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i,gMax=INT_MIN;
        if(nums.size()==1)
            return nums[0];
        vector<int> dpMax(nums.size(),0);
        vector<int> dpMin(nums.size(),0);
        dpMax[0]=nums[0];
        dpMin[0]=nums[0];
        for(i=1;i<nums.size();i++){
            dpMax[i]=max({nums[i],dpMax[i-1]*nums[i],dpMin[i-1]*nums[i]});
            dpMin[i]=min({nums[i],dpMax[i-1]*nums[i],dpMin[i-1]*nums[i]});
            if(dpMax[i]>gMax)
                gMax=dpMax[i];
        }
        return gMax;
    }
};
