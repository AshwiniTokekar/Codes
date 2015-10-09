#include<iostream>
 vector<int> singleNumber(vector<int>& nums) {

        int result=0,size=nums.size(),temp,num1=0,num2=0;

        for(int i=0;i<size;i++)

        {

            result^=nums[i];

        }

        temp=((~(result-1))&result);

      //  cout<<temp<<"\n";

        for(int i=0;i<size;i++)

        {

            if(temp&nums[i])

               num1^=nums[i];

            

        }

        num2=result^num1;

        vector<int>ans={num1,num2};//(num1);

        return ans;

    }
