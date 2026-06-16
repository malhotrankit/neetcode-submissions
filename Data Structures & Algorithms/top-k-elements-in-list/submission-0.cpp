class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int i,n,flag=0;
        n=nums.size();
        for(i=0;i<n;i++)
            um[nums[i]]++;
        vector<vector<int>> v(n+1);
        for(const auto& [f,s]:um)
        {
            v[s].push_back(f);
        }
        vector<int>ans;
        for(i=n;i>0;i--){
            for(auto it:v[i]){
                ans.push_back(it);
                if(ans.size()==k){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        return ans;
    }
};
