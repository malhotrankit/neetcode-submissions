class Solution {
public:
    bool isAnagram(string s, string t) {
        int anagram[26],i,n;
        n=s.length();
        if(n!=t.length())
            return false;
        for(i=0;i<26;i++)
            anagram[i] = 0;
        for(i=0;i<n;i++)
            anagram[s[i]-97]++;
        for(i=0;i<n;i++)
            anagram[t[i]-97]--;
        for(i=0;i<26;i++)
            if(anagram[i]!=0)
                return false;
        return true;
        

    }
};
