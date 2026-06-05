class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i,n,m,j,array[27];
        vector<string> v;
        vector<string> v1;
        vector<vector<string>> vv;
        for(i=0;i<strs.size();i++){
            for(j=0;j<27;j++){
                array[j]=0;
            }
            string s = strs[i];
            string result = "";
            for(j=0;j<s.length();j++){
                array[s[j]-97]++;
            }
            for(j=0;j<27;j++){
                //cout<<array[j]<<" ";
                result+= to_string(array[j]) + "#";
            }
            v.push_back(result);
        }
        for(i=0;i<v.size();i++){
            v1.clear();
            if(v[i]!="-1"){
                for(j=i+1;j<v.size();j++){
                    if(v[j]!="-1"&&v[i]==v[j]){
                        v1.push_back(strs[j]);
                        v[j]="-1";
                    }
                }
                v1.push_back(strs[i]);
                v[i]="-1";
                vv.push_back(v1);
            }
        }
        return vv;
    }
};
