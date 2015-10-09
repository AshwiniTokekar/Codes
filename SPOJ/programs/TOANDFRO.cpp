#include <iostream>
using namespace std;
char mat[25][25];
int main()
{
  int nol,siz;
  char inp[300];
  do
  {
    cin>>siz;
    if(siz==0)
      break;
    cin>>inp;
    nol=0;
    int i=0,j=0;
    while(inp[i]!='\0')
    {
       //cout<<inp[i];
       if(nol%2==0)
        mat[nol][j]=inp[i];
       else
         mat[nol][siz-j-1]=inp[i];
       j++;
       i++;
       if(j==siz)
        {
          nol++;
          j=0;
        }
    }
    cout<<'\n';
    for(i=0;i<siz;i++)
      for(j=0;j<nol;j++)
        cout<<mat[j][i];
    cout<<'\n';


  }while(siz!=0);
 return 0;
}

