class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> >aux(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            aux[i][0]=1;
        }
        for(int i=1;i<n;i++)
        {
            aux[0][i]=1;
        }
       /* for(int i=0;i<m;i++)
            {
             for(int j=0;j<n;j++)
             {
              cout<<aux[i][j]<<" ";
             }
             cout<<"\n";
            }
            cout<<"\n\n";*/
        for(int i=1;i<m;i++)
         for(int j=1;j<n;j++)
         {
             aux[i][j]=aux[i-1][j]+aux[i][j-1];
         }
    /*     for(int i=0;i<m;i++)
            {
             for(int j=0;j<n;j++)
             {
              cout<<aux[i][j]<<" ";
             }
             cout<<"\n";
            }*/
        return aux[m-1][n-1];
        
    }
};