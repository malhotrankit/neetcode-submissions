class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i,n;
        n=s.length();
        vector<int> dp(n+1,false);
        dp[n]=true;
        for(i=n-1;i>=0;i--){
            for(auto it:wordDict){
                if(i+it.length()<=s.length()&&s.substr(i,it.length())==it){
                    dp[i]=dp[i+it.length()];
                }
                if(dp[i])
                    break;
            }
        }
        return dp[0];
    }
};
