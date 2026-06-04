class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,n;
        unordered_map<int,int> um;
        vector<int> v;
        n=nums.size();
        for(i=0;i<n;i++){
            um.insert({nums[i],i});
        }
        for(i=0;i<n;i++){
            auto it = um.find(target-nums[i]);
            if(it != um.end() && i != it->second){
                if(i < it->second){
                    v.push_back(i);
                    v.push_back(it->second);
                    return v;
                }
                else {
                    v.push_back(it->second);
                    v.push_back(i);
                    return v;
                }
            }
        }
    }
};
