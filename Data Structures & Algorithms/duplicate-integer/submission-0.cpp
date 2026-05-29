class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int i;
        unordered_map<int,int> um;
        for(i=0;i<nums.size();i++){
            auto it = um.find(nums[i]);
            if(it==um.end()){
                um.insert({nums[i],1});
            }
            else 
                return true;
        }
        return false;
    }
};