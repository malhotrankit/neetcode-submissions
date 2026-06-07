class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int i,j,n,m,k,l,x,y,max = INT_MIN;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        n = grid.size();
        m = grid[0].size();
        if(n<1)
            return 0;
        queue<pair<int,int>> q;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                    grid[i][j]=0;
                }
                else if(grid[i][j]==1){
                    grid[i][j]=INT_MAX;
                }
                else
                    continue;  
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto d:dir){
                k = curr.first;
                l = curr.second;
                x = d.first;
                y = d.second;
                if(k+x>=0&&k+x<n&&l+y>=0&&l+y<m&&grid[k+x][l+y]>grid[k][l]+1){
                    grid[k+x][l+y]=grid[k][l]+1;
                    q.push(make_pair(k+x,l+y));
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]==INT_MAX){
                    return -1;
                }
                if(max < grid[i][j]){
                    max = grid[i][j];
                }  
            }
        }
        return max;
    }
};
