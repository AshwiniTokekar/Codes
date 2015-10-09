vector<int> productExceptSelf(vector<int>& nums) {
        vector <int>output(nums.size());
        int size=nums.size();
        int pdt=1;
        for(int i=0;i<size;i++)
        {
            output[i]=pdt;
            pdt*=nums[i];
        }
        pdt=1;
        for(int i=size-1;i>=0;i--)
        {
            output[i]*=pdt;
            pdt*=nums[i];
        }
        return output;
    }