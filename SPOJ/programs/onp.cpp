# include <iostream>
# include <stack>
#include <cstring>
using namespace std;
int main()
{
   stack <char> rpn;
   char inp[450];
  // char out[450];
   int nos;
   cin>>nos;
   for(int i=0;i<nos;i++)
   {
      cin>>inp;
      int j=0,k=0;
      char out[450];
      memset(out,'\0',450);
      while(inp[j]!='\0')
      {
         if(inp[j]=='(')
           rpn.push(inp[j]);
         else if(inp[j]=='+'||inp[j]=='-'||inp[j]=='*'||inp[j]=='/'||inp[j]=='^')
           rpn.push(inp[j]);
        else if(islower(inp[j]))
           {
             out[k]=inp[j];
             k++;
           }
        else if(inp[j]==')')
        {
            out[k]=rpn.top();
            rpn.pop();
            rpn.pop();
            k++;
        }
         j++;
      }
     cout<<out<<"\n";
   }
   return 0;
}

