//Approach-1
int randompartition(vector<int>&nums,int l,int r)
    {
        int n=r-l+1;
        int pos=rand()%n;
        int temp=nums[l+pos];
        nums[l+pos]=nums[r];
        nums[r]=nums[l+pos];
        return pos;
    }
    int kthlargest(vector<int>&nums,int k,int l,int r)
    {
       // cout<<l<<" "<<r<<" "<<k<<"\n";
        if(k>0&&k<=r-l+1)
        {
        int pos=randompartition(nums,l,r);
      //  cout<<pos<<"\n";
        if(pos-l==k-1)
            return nums[pos];
        if(pos-l>k-1)
            return kthlargest(nums,k,l,pos-1);
        return kthlargest(nums,k-pos+l-1,pos+1,r);
        }
        return INT_MAX;
    }
    int findKthLargest(vector<int>& nums, int k) {
       //to find kth smallest change nums.size()-k+1===>k
       int ans=kthlargest(nums,nums.size()-k+1,0,nums.size());
        return ans;
    }
//Approach-2
//Simple priority queue
 int findKthLargest(vector<int>& nums, int k) {
        int size=nums.size();
        priority_queue<int>pq;
        for(auto n : nums)
        {
            //int n=nums[i];
            pq.push(n);
        }    
        int num;
        for(int i=1;i<=k;i++)
        {
            num=pq.top();
          //  cout<<num<<" ";
            pq.pop();
        }
        return num;
    }    