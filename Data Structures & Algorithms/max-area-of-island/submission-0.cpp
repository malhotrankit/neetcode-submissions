class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i,j,n,m,count=0,max=0;
        vector<pair<int,int>> v = {{-1,0},{1,0},{0,1},{0,-1}};
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> q;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)
            {
                count=0;
                if(grid[i][j]==1){
                    count++;
                    grid[i][j]=0;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        auto curr = q.front();
                        q.pop();
                        for(auto it:v){
                            int k = it.first;
                            int l = curr.first;
                            int x = it.second;
                            int y = curr.second;
                            if(k+l>=0&&k+l<n&&x+y>=0&&x+y<m){
                                if(grid[k+l][x+y]==1){
                                    count++;
                                    grid[k+l][x+y]=0;
                                    q.push(make_pair(k+l,x+y));
                                }

                            }
                        }
                    }
                }
                if(max<count)
                    max=count;
            }
        }
        return max;
    }
};
