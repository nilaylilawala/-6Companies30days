class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int maxi=0,pos=0,n=nums.size();
        vector<int> lis(n,-1),checker(n,1),ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && checker[i]<=checker[j]){
                    lis[i]=j;
                    checker[i]=checker[j]+1;
                    if(checker[i]>maxi){
                        maxi=checker[i];
                        pos=i;
                    }
                }
            }
        }
        while(lis[pos]!=-1){
            ans.push_back(nums[pos]);
            pos=lis[pos];
        }
        ans.push_back(nums[pos]);
        return ans;
    }
};
