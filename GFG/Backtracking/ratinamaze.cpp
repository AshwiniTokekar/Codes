#include <iostream>
using namespace std;
const int N=4;
int sol[N][N];
int maze[N][N];
int mazex[4]={-1,1,0,0};
int mazey[4]={0,0,-1,1};
bool isSafe(int x,int y)
{
	if(x>=0&&x<N&&y>=0&&y<N&&maze[x][y]==1&&sol[x][y]==0)
	{
         return true;
	}
	return false;
}
bool solvemazeutil(int x,int y)
{
  if(x==N-1&&y==N-1)
  {
    sol[x][y]=1;
    return true;
  }
  else
  {
    sol[x][y]=1;
    for(int i=0;i<4;i++)
    {
      int next_x=x+mazex[i];
      int next_y=y+mazey[i];
      if(isSafe(next_x,next_y))
      {
        if(solvemazeutil(next_x,next_y))
          return true;
      }
    }
    sol[x][y]=0;
    return false;
  }

}
bool solvemaze()
{
	if(solvemazeutil(0,0)==true)
	{
		cout<<"Solution is present\n";
//		printsolution();
	}
	else
		cout<<"Solution doesn't exist\n";
}
int main()
{
	maze[0][0]=1;
        maze[0][1]=0;
        maze[0][2]=0;
        maze[0][3]=0;
        maze[1][0]=1;
        maze[1][1]=1;
        maze[1][2]=0;
        maze[1][3]=1;
        maze[2][0]=0;
        maze[2][1]=1;
        maze[2][2]=0;
        maze[2][3]=0;
        maze[3][0]=1;
        maze[3][1]=1;
        maze[3][2]=1;
        maze[3][3]=1;
        for(int i=0;i<N;i++)
          for(int j=0;j<N;j++)
          {
            sol[i][j]=0;
          }
    solvemaze();
	return 0;
}
