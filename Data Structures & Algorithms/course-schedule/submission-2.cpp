class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n,i;
        n=numCourses;
        vector<vector<int>> preGraph(n);
        vector<int> courses(n,0);
        for(auto& p:prerequisites)
            preGraph[p[1]].push_back(p[0]);
        for(i=0;i<n;i++){
            if(!dfs(i,courses,preGraph))
                return false;
        }
        return true;
    }

    bool dfs(int node,vector<int>& courses,vector<vector<int>>& preGraph){
        if(courses[node]==1)
            return false;
        //if(courses[node]==2)
            //return true;
        courses[node]=1;
        for(auto it:preGraph[node]){
            if(!dfs(it,courses,preGraph))
                return false;
        }
        courses[node]=2;
        return true;
    }
};
