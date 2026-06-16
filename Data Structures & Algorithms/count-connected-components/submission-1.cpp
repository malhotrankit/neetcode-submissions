class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int i,count=0;
        vector<vector<int>> g(n);
        vector<bool> visited(n,false);
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        for(i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,g,visited,-1);
                count++;
                //cout<<i<<" ";
                for(int j=0;j<n;j++)
                    cout<<visited[j]<<" ";
            }
            cout<<"\n";
        }
        return count;
    }
    void dfs(int node, vector<vector<int>>& g,vector<bool>& visited,int parent){
        if(visited[node]==true)
            return;
        visited[node]=true;
        for(auto it:g[node]){
            if(it==parent)
                continue;
            //visited[it]=true;
            dfs(it,g,visited,node);
        }
    }
};
