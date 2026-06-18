class Solution {
public:
    int characterReplacement(string s, int k) {
        int lt=0,rt=0,maxCount=0,ans=0;
        vector<int> visited(26,0);
        while(lt<=rt&&rt<s.length()){
            visited[s[rt]-65]++;
            maxCount = max(maxCount,visited[s[rt]-65]);
            while(rt-lt+1-maxCount>k){
                visited[s[lt]-65]--;
                auto max_it = std::max_element(visited.begin(), visited.end());
                maxCount = *max_it;
                lt++;
            }
            ans = max(ans,rt-lt+1);
            rt++;
        }
        return ans;
    }
};
