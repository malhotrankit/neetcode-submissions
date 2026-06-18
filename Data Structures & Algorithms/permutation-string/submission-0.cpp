class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i,n,m,lt=0,rt,count=0;
        vector<int> v1(26,0),v2(26,0);
        n=s1.length();
        rt=n-1;
        m=s2.length();
        if(m<n)
            return false;
        for(i=0;i<n;i++){
            v1[s1[i]-97]++;
            v2[s2[i]-97]++;
        }
        while(lt<=rt&&rt<m){
            count=0;
            for(i=0;i<26;i++){
                if(v1[i]==v2[i])
                    count++;
            }
            if(count==26)
                return true;
            v2[s2[lt]-97]--;
            lt++;
            if(rt+1<m){
                rt++;
                v2[s2[rt]-97]++;
            }
        }
        return false;
        
    }
};
