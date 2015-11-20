class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int> >aux(m,vector<int>(n,0));
        if(grid[0][0]==0)
          aux[0][0]=1;
        for(int i=1;i<m;i++)
        {
            if(grid[i][0]==0&&aux[i-1][0]==1)
                aux[i][0]=1;
        }
        for(int i=1;i<n;i++)
        {
            if(grid[0][i]==0&&aux[0][i-1]==1)
                aux[0][i]=1;
        }
        
        for(int i=1;i<m;i++)
           for(int j=1;j<n;j++)
           {
               if(grid[i][j]!=1)
               {
                   aux[i][j]=aux[i-1][j]+aux[i][j-1];
               }
               
           }
        
           
        return aux[m-1][n-1];
    }
};