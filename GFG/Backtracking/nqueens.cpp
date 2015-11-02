#include <iostream>
using namespace std;
const int N=4;
bool isSafe(int board[N][N],int x,int y)
{
  for(int i=0;i<y;i++)
  {
    if(board[x][i]==1)
        return false;
  }

  for(int i=x,j=y;i>=0&&j>=0;i--,j--)
  {
    if(board[i][j])
        return false;
  }

  for(int i=x,j=y;i<N&&j>=0;i++,j--)
  {
    if(board[i][j])
       return false;
  }
  return true;

}
bool Nqueensutil(int board[N][N],int col)
{
    if(col>=N)
      return true;
    for(int i=0;i<N;i++)
    {
      board[i][N]=1;
      if(isSafe(board,i,col))
        return true;
      board[i][col]=0;
    }
    return false;
}
bool Nqueens(int board[N][N])
{
    if(Nqueensutil(board,0))
      cout<<"Solution exists\n";
    else
      cout<<"No solution\n";
}
int main()
{
  int board[4][4];
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      board[i][j]=0;
  Nqueens(board);

  return 0;
}
