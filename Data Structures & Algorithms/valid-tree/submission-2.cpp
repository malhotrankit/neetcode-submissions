class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int i;
        if(edges.size()!=n-1)
            return false;
        vector<vector<int>> preGraph(n);
        vector<int> courses(n,0);
        for(auto& p:edges){
            preGraph[p[0]].push_back(p[1]);
            preGraph[p[1]].push_back(p[0]);
        }
        for(i=0;i<n;i++){
            if(!dfs(i,courses,preGraph,-1))
                return false;
        }
        return true;
    }
    bool dfs(int node,vector<int>& courses,vector<vector<int>>& preGraph,int parent){
        if(courses[node]==1)
            return false;
        if(courses[node]==2)
            return true;
        courses[node]=1;
        for(auto it:preGraph[node]){
            if(parent==it)
                continue;
            if(!dfs(it,courses,preGraph,node))
                return false;
        }
        courses[node]=2;
        return true;
    }
};
