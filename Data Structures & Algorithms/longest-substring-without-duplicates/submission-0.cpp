class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lt,rt,max=0;
        vector<bool> visited(128,false);
        lt=0;
        rt=0;
        while(lt<=rt&&rt<s.length()){
            while(visited[s[rt]]==true){
                visited[s[lt]]=false;
                lt++;
            }
            visited[s[rt]]=true;
            if(max<rt-lt+1){
                max=rt-lt+1;
            }
            rt++;
        }
        return max;
    }
};
