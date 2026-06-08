class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n,m,i,j,x,y,w,z;
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        n = board.size();
        m = board[0].size();
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(board[i][j]=='O'&&(i==n-1||j==m-1||i==0||j==0)){
                    q.push(make_pair(i,j));
                    board[i][j]='A';
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            x = curr.first;
            y = curr.second;
            for(auto d:dir){
                w = d.first;
                z = d.second;
                if(x+w>=0&&x+w<n&&y+z>=0&&y+z<m&&board[x+w][y+z]=='O'){
                    board[x+w][y+z]='A';
                    q.push(make_pair(x+w,y+z));
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='A'){
                    board[i][j]='O';
                }
                else
                    continue;
            }
        }      
    }
};
