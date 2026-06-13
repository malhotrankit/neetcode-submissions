class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int i,j,n,m,k,l,x,y;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> v;
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool> (m,false));
        vector<vector<bool>> atlantic(n,vector<bool> (m,false));
        for(i=0;i<n;i++){
            q1.push(make_pair(i,0));
            pacific[i][0]=true;
            q2.push(make_pair(i,m-1));
            atlantic[i][m-1]=true;
        }
        for(i=0;i<m;i++){
            q1.push(make_pair(0,i));
            pacific[0][i]=true;
            q2.push(make_pair(n-1,i));
            atlantic[n-1][i]=true;
        }
        while(!q1.empty()){
            auto curr = q1.front();
            q1.pop();
            k = curr.first;
            l = curr.second;
            for(auto d:dir){
                x = d.first;
                y = d.second;
                if(k+x>=0&&k+x<n&&l+y>=0&&l+y<m&&pacific[k+x][l+y]!=true&&heights[k+x][l+y]>=heights[k][l]){
                    pacific[k+x][l+y]=true;
                    q1.push(make_pair(k+x,l+y));
                }
            }
        }
        while(!q2.empty()){
            auto curr = q2.front();
            q2.pop();
            k = curr.first;
            l = curr.second;
            for(auto d:dir){
                x = d.first;
                y = d.second;
                if(k+x>=0&&k+x<n&&l+y>=0&&l+y<m&&atlantic[k+x][l+y]!=true&&heights[k+x][l+y]>=heights[k][l]){
                    atlantic[k+x][l+y]=true;
                    q2.push(make_pair(k+x,l+y));
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(pacific[i][j]==true&&atlantic[i][j]==true){
                    v.push_back({i,j});
                } 
            }
        }
        return v;

    }
};
