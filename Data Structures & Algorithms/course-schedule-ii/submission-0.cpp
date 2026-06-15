class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n,i;
        n=numCourses;
        vector<vector<int>> preGraph(n);
        vector<int> courses(n,0);
        vector<int> ans;
        for(auto& p:prerequisites)
            preGraph[p[0]].push_back(p[1]);
        for(i=0;i<n;i++){
            if(!dfs(i,courses,preGraph,ans)){
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
    bool dfs(int node,vector<int>& courses,vector<vector<int>>& preGraph,vector<int>& ans){
        if(courses[node]==1)
            return false;
        if(courses[node]==2)
            return true;
        courses[node]=1;
        for(auto it:preGraph[node]){
            if(!dfs(it,courses,preGraph,ans))
                return false;
        }
        courses[node]=2;
        ans.push_back(node);
        return true;
    }
};
