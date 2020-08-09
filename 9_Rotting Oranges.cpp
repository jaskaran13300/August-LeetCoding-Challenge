typedef pair<int,int> pii;
class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=0;
        if(r){
            c=grid[0].size();
        }
        int mins=-1;
        queue<pii>q;
        int oranges=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    oranges++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        if(oranges==0){
            return 0;
        }
        
        vector<pii>direction={{-1,0},{0,-1},{1,0},{0,1}};
        
        while(!q.empty()){
            mins++;
            int size=q.size();
            int count=0;
            while(count<size){
                pii front=q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int x=front.first+direction[i].first;
                    int y=front.second+direction[i].second;
                    if(x>=0 && y>=0 && x<r && y<c && grid[x][y]==1){
                        grid[x][y]=2;
                        oranges--;
                        q.push({x,y});
                    }
                }
                
                count++;
            }
        }
        if(oranges==0)
            return mins;
        return -1;
    }
};
